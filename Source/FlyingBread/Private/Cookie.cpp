#include "Cookie.h"

// 생성자
ACookie::ACookie()
{
    // 루트 컴포넌트 초기화
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    PrimaryActorTick.bCanEverTick = true;

    // 기본 값 초기화
    MoveSpeed = 150.0f;
    MaxRange = 100.0f;
    MoveDirection = 1;  // 1: +Z 방향 (위로), -1: -Z 방향 (아래로)
}

void ACookie::BeginPlay()
{
    Super::BeginPlay();

    // 시작 위치 저장
    StartLocation = GetActorLocation();
}

void ACookie::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // DeltaTime 제한 (프레임 드롭 방지)
    DeltaTime = FMath::Clamp(DeltaTime, 0.0f, 0.1f);

    // 현재 위치
    FVector CurrentLocation = GetActorLocation();

    // 이번 프레임에 이동할 Offset (Z축 기준)
    FVector Offset = FVector(0.0f, 0.0f, MoveSpeed * DeltaTime * MoveDirection);
    FVector NewLocation = CurrentLocation + Offset;

    // 새 위치에서의 DeltaZ: (NewLocation.Z - StartLocation.Z)
    float NewDeltaZ = NewLocation.Z - StartLocation.Z;

    // 디버그용 로그
    UE_LOG(LogTemp, Warning, TEXT("Current Location: %s"), *CurrentLocation.ToString());
    UE_LOG(LogTemp, Warning, TEXT("Move Direction: %d"), MoveDirection);
    UE_LOG(LogTemp, Warning, TEXT("NewDeltaZ: %f, MaxRange: %f"), NewDeltaZ, MaxRange);

    // 위쪽으로 MaxRange를 넘어갔을 때
    if (NewDeltaZ >= MaxRange)
    {
        ReverseDirection();

        // 초과분(오버슈트) 계산
        float OverShoot = NewDeltaZ - MaxRange;
        // 오버슈트만큼 다시 빼서 위치를 보정
        NewLocation.Z = StartLocation.Z + MaxRange - OverShoot;

        UE_LOG(LogTemp, Warning, TEXT("Overshoot: %f"), OverShoot);
        UE_LOG(LogTemp, Warning, TEXT("New Location After Correction: %s"), *NewLocation.ToString());
    }
    // 아래쪽으로 MaxRange를 넘어갔을 때
    else if (NewDeltaZ <= -MaxRange)
    {
        ReverseDirection();

        float OverShoot = -MaxRange - NewDeltaZ;
        NewLocation.Z = StartLocation.Z - MaxRange + OverShoot;

        UE_LOG(LogTemp, Warning, TEXT("Overshoot: %f"), OverShoot);
        UE_LOG(LogTemp, Warning, TEXT("New Location After Correction: %s"), *NewLocation.ToString());
    }

    // 최종 위치 적용
    SetActorLocation(NewLocation);
}

void ACookie::ReverseDirection()
{
    // 이동 방향 반전
    MoveDirection *= -1;

    // 디버깅 로그
    UE_LOG(LogTemp, Warning, TEXT("Direction Reversed: %d"), MoveDirection);
}