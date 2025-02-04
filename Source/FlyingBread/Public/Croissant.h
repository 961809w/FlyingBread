#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Croissant.generated.h"

UCLASS()
class FLYINGBREAD_API ACroissant : public AActor
{
    GENERATED_BODY()

public:
    // 생성자
    ACroissant();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    // 루트 컴포넌트
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Chair|Components", meta = (AllowPrivateAccess = "true"))
    USceneComponent* SceneRoot;

    // 스태틱 메시 컴포넌트
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Chair|Components", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* StaticMeshComp;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chair|Platform Settings", meta = (AllowPrivateAccess = "true"))
    float RotationSpeed;


    // 시작 위치
    FVector StartLocation;


};
