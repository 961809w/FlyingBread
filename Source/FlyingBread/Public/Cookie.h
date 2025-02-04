#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cookie.generated.h"

UCLASS()
class FLYINGBREAD_API ACookie : public AActor
{
    GENERATED_BODY()

public:
    // ������
    ACookie();

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

    // �̵� �ӵ�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chair|Platform Settings", meta = (AllowPrivateAccess = "true"))
    float MoveSpeed;

    // �ִ� �̵� ���� (Z�� ����)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chair|Platform Settings", meta = (AllowPrivateAccess = "true"))
    float MaxRange;

    // �̵� ���� (1: ����, -1: �Ʒ���)
    int32 MoveDirection;

    // ���� ��ġ
    FVector StartLocation;

    // �̵� ���� ���� �Լ�
    void ReverseDirection();
};
