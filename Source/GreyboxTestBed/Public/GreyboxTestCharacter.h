// GreyboxTestCharacter.h
// Placeholder UE5 character used to test C++ movement logic and replication.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GreyboxTestCharacter.generated.h"

class UCharacterMovementComponent;
class UInputComponent;

UCLASS()
class GREYBOXTESTBED_API AGreyboxTestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGreyboxTestCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the character is possessed by a controller.
	virtual void PossessedBy(AController* NewController) override;

	// Horizontal move input bound to forward/side axes.
	void MoveForward(const float Value);
	void MoveRight(const float Value);

	// Jump wrapper; keeps the jump request routed through the movement component.
	void JumpAction();
	void StopJumpAction();

	// Debug helper: logs current movement mode, speed, and ground state once per tick.
	void LogMovementState(const float DeltaTime);

	// Tunable speed for the greybox walk, kept here so it can be tweaked in-editor.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greybox|Movement")
	float WalkSpeed;

	// How often the debug movement state line is printed (seconds). 0 disables it.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Greybox|Debug")
	float DebugLogInterval;

private:
	float LastDebugLogTime;
};
