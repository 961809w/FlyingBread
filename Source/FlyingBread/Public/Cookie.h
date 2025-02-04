#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cookie.generated.h"

UCLASS()
class FLYINGBREAD_API ACookie : public AActor
{
    GENERATED_BODY()

public:
    // 생성자
    ACookie();

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

    // 이동 속도
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chair|Platform Settings", meta = (AllowPrivateAccess = "true"))
    float MoveSpeed;

    // 최대 이동 범위 (Z축 기준)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chair|Platform Settings", meta = (AllowPrivateAccess = "true"))
    float MaxRange;

    // 이동 방향 (1: 위쪽, -1: 아래쪽)
    int32 MoveDirection;

    // 시작 위치
    FVector StartLocation;

    // 이동 방향 반전 함수
    void ReverseDirection();
};
