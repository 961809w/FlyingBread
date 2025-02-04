#include "Cookie.h"

// ������
ACookie::ACookie()
{
    // ��Ʈ ������Ʈ �ʱ�ȭ
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    PrimaryActorTick.bCanEverTick = true;

    // �⺻ �� �ʱ�ȭ
    MoveSpeed = 150.0f;
    MaxRange = 100.0f;
    MoveDirection = 1;  // 1: +Z ���� (����), -1: -Z ���� (�Ʒ���)
}

void ACookie::BeginPlay()
{
    Super::BeginPlay();

    // ���� ��ġ ����
    StartLocation = GetActorLocation();
}

void ACookie::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // DeltaTime ���� (������ ��� ����)
    DeltaTime = FMath::Clamp(DeltaTime, 0.0f, 0.1f);

    // ���� ��ġ
    FVector CurrentLocation = GetActorLocation();

    // �̹� �����ӿ� �̵��� Offset (Z�� ����)
    FVector Offset = FVector(0.0f, 0.0f, MoveSpeed * DeltaTime * MoveDirection);
    FVector NewLocation = CurrentLocation + Offset;

    // �� ��ġ������ DeltaZ: (NewLocation.Z - StartLocation.Z)
    float NewDeltaZ = NewLocation.Z - StartLocation.Z;

    // ����׿� �α�
    UE_LOG(LogTemp, Warning, TEXT("Current Location: %s"), *CurrentLocation.ToString());
    UE_LOG(LogTemp, Warning, TEXT("Move Direction: %d"), MoveDirection);
    UE_LOG(LogTemp, Warning, TEXT("NewDeltaZ: %f, MaxRange: %f"), NewDeltaZ, MaxRange);

    // �������� MaxRange�� �Ѿ�� ��
    if (NewDeltaZ >= MaxRange)
    {
        ReverseDirection();

        // �ʰ���(������Ʈ) ���
        float OverShoot = NewDeltaZ - MaxRange;
        // ������Ʈ��ŭ �ٽ� ���� ��ġ�� ����
        NewLocation.Z = StartLocation.Z + MaxRange - OverShoot;

        UE_LOG(LogTemp, Warning, TEXT("Overshoot: %f"), OverShoot);
        UE_LOG(LogTemp, Warning, TEXT("New Location After Correction: %s"), *NewLocation.ToString());
    }
    // �Ʒ������� MaxRange�� �Ѿ�� ��
    else if (NewDeltaZ <= -MaxRange)
    {
        ReverseDirection();

        float OverShoot = -MaxRange - NewDeltaZ;
        NewLocation.Z = StartLocation.Z - MaxRange + OverShoot;

        UE_LOG(LogTemp, Warning, TEXT("Overshoot: %f"), OverShoot);
        UE_LOG(LogTemp, Warning, TEXT("New Location After Correction: %s"), *NewLocation.ToString());
    }

    // ���� ��ġ ����
    SetActorLocation(NewLocation);
}

void ACookie::ReverseDirection()
{
    // �̵� ���� ����
    MoveDirection *= -1;

    // ����� �α�
    UE_LOG(LogTemp, Warning, TEXT("Direction Reversed: %d"), MoveDirection);
}