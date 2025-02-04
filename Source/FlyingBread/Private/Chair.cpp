#include "Chair.h"

// 생성자
AChair::AChair()
{
    // 루트 컴포넌트 초기화
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    PrimaryActorTick.bCanEverTick = true;

    // 기본 값 초기화
    MoveSpeed = 100.0f;
    MaxRange = 180.0f;
    MoveDirection = 1;  // 1: +X 방향, -1: -X 방향
}

void AChair::BeginPlay()
{
    Super::BeginPlay();

    // 시작 위치 저장
    StartLocation = GetActorLocation();
}

void AChair::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // DeltaTime 제한 (프레임 드롭 방지)
    DeltaTime = FMath::Clamp(DeltaTime, 0.0f, 0.1f);

    // 현재 위치
    FVector CurrentLocation = GetActorLocation();

    // 이번 프레임에 이동할 Offset (X축 기준)
    FVector Offset = FVector(MoveSpeed * DeltaTime * MoveDirection, 0.0f, 0.0f);
    FVector NewLocation = CurrentLocation + Offset;

    // 새 위치에서의 DeltaX: (NewLocation - StartLocation)
    float NewDeltaX = NewLocation.X - StartLocation.X;

    // 디버그용 로그
    UE_LOG(LogTemp, Warning, TEXT("Current Location: %s"), *CurrentLocation.ToString());
    UE_LOG(LogTemp, Warning, TEXT("Move Direction: %d"), MoveDirection);
    UE_LOG(LogTemp, Warning, TEXT("NewDeltaX: %f, MaxRange: %f"), NewDeltaX, MaxRange);

    // +X 방향으로 MaxRange를 넘어갔을 때
    if (NewDeltaX >= MaxRange)
    {
        ReverseDirection();

        // 초과분(오버슈트) 계산
        float OverShoot = NewDeltaX - MaxRange;
        // 오버슈트만큼 다시 빼서 위치를 보정
        NewLocation.X = StartLocation.X + MaxRange - OverShoot;

        UE_LOG(LogTemp, Warning, TEXT("Overshoot: %f"), OverShoot);
        UE_LOG(LogTemp, Warning, TEXT("New Location After Correction: %s"), *NewLocation.ToString());
    }
    // -X 방향으로 MaxRange를 넘어갔을 때 (왕복 이동을 원하는 경우)
    else if (NewDeltaX <= -MaxRange)
    {
        ReverseDirection();

        float OverShoot = -MaxRange - NewDeltaX;
        NewLocation.X = StartLocation.X - MaxRange + OverShoot;

        UE_LOG(LogTemp, Warning, TEXT("Overshoot: %f"), OverShoot);
        UE_LOG(LogTemp, Warning, TEXT("New Location After Correction: %s"), *NewLocation.ToString());
    }

    // 최종 위치 적용
    SetActorLocation(NewLocation);
}

void AChair::ReverseDirection()
{
    // 이동 방향 반전
    MoveDirection *= -1;

    // 디버깅 로그
    UE_LOG(LogTemp, Warning, TEXT("Direction Reversed: %d"), MoveDirection);
}
