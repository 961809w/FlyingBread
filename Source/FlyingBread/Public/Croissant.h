#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Croissant.generated.h"

UCLASS()
class FLYINGBREAD_API ACroissant : public AActor
{
    GENERATED_BODY()

public:
    // ������
    ACroissant();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    // ��Ʈ ������Ʈ
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Chair|Components", meta = (AllowPrivateAccess = "true"))
    USceneComponent* SceneRoot;

    // ����ƽ �޽� ������Ʈ
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Chair|Components", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* StaticMeshComp;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chair|Platform Settings", meta = (AllowPrivateAccess = "true"))
    float RotationSpeed;


    // ���� ��ġ
    FVector StartLocation;


};
