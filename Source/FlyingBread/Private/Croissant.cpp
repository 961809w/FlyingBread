#include "Croissant.h"

// ������
ACroissant::ACroissant()
{
    // ��Ʈ ������Ʈ �ʱ�ȭ
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    PrimaryActorTick.bCanEverTick = true;

    RotationSpeed = 90.0f;

}

void ACroissant::BeginPlay()
{
    Super::BeginPlay();

}

void ACroissant::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


    if (!FMath::IsNearlyZero(RotationSpeed))
    {
        AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));

    }

}


