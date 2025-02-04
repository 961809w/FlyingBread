#include "Chair.h"

// ������
AChair::AChair()
{
    // ��Ʈ ������Ʈ �ʱ�ȭ
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    PrimaryActorTick.bCanEverTick = true;

    // �⺻ �� �ʱ�ȭ
    MoveSpeed = 100.0f;
    MaxRange = 180.0f;
    MoveDirection = 1;  // 1: +X ����, -1: -X ����
}

void AChair::BeginPlay()
{
    Super::BeginPlay();

    // ���� ��ġ ����
    StartLocation = GetActorLocation();
}

void AChair::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // DeltaTime ���� (������ ��� ����)
    DeltaTime = FMath::Clamp(DeltaTime, 0.0f, 0.1f);

    // ���� ��ġ
    FVector CurrentLocation = GetActorLocation();

    // �̹� �����ӿ� �̵��� Offset (X�� ����)
    FVector Offset = FVector(MoveSpeed * DeltaTime * MoveDirection, 0.0f, 0.0f);
    FVector NewLocation = CurrentLocation + Offset;

    // �� ��ġ������ DeltaX: (NewLocation - StartLocation)
    float NewDeltaX = NewLocation.X - StartLocation.X;

    // ����׿� �α�
    UE_LOG(LogTemp, Warning, TEXT("Current Location: %s"), *CurrentLocation.ToString());
    UE_LOG(LogTemp, Warning, TEXT("Move Direction: %d"), MoveDirection);
    UE_LOG(LogTemp, Warning, TEXT("NewDeltaX: %f, MaxRange: %f"), NewDeltaX, MaxRange);

    // +X �������� MaxRange�� �Ѿ�� ��
    if (NewDeltaX >= MaxRange)
    {
        ReverseDirection();

        // �ʰ���(������Ʈ) ���
        float OverShoot = NewDeltaX - MaxRange;
        // ������Ʈ��ŭ �ٽ� ���� ��ġ�� ����
        NewLocation.X = StartLocation.X + MaxRange - OverShoot;

        UE_LOG(LogTemp, Warning, TEXT("Overshoot: %f"), OverShoot);
        UE_LOG(LogTemp, Warning, TEXT("New Location After Correction: %s"), *NewLocation.ToString());
    }
    // -X �������� MaxRange�� �Ѿ�� �� (�պ� �̵��� ���ϴ� ���)
    else if (NewDeltaX <= -MaxRange)
    {
        ReverseDirection();

        float OverShoot = -MaxRange - NewDeltaX;
        NewLocation.X = StartLocation.X - MaxRange + OverShoot;

        UE_LOG(LogTemp, Warning, TEXT("Overshoot: %f"), OverShoot);
        UE_LOG(LogTemp, Warning, TEXT("New Location After Correction: %s"), *NewLocation.ToString());
    }

    // ���� ��ġ ����
    SetActorLocation(NewLocation);
}

void AChair::ReverseDirection()
{
    // �̵� ���� ����
    MoveDirection *= -1;

    // ����� �α�
    UE_LOG(LogTemp, Warning, TEXT("Direction Reversed: %d"), MoveDirection);
}
