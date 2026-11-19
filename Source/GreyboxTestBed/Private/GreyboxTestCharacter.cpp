// GreyboxTestCharacter.cpp
// Placeholder UE5 character movement testbed implementation.

#include "GreyboxTestCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "Engine/Controller.h"

AGreyboxTestCharacter::AGreyboxTestCharacter()
	: WalkSpeed(300.0f)
	, DebugLogInterval(1.0f)
	, LastDebugLogTime(0.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	// Start from the stock character movement component and tune it for greybox use.
	if (UCharacterMovementComponent* Move = GetCharacterMovement())
	{
		Move->bOrientRotationToMovement = true;
		Move->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
		Move->MaxWalkSpeed = WalkSpeed;
		Move->JumpZVelocity = 420.0f;
		Move->AirControl = 0.2f;
	}
}

void AGreyboxTestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LogMovementState(DeltaTime);
}

void AGreyboxTestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Binding names are resolved against the project input map; axes are placeholders
	// until the UE project settings are filled in Milestone 1.
	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("MoveForward", this, &AGreyboxTestCharacter::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &AGreyboxTestCharacter::MoveRight);
		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGreyboxTestCharacter::JumpAction);
		PlayerInputComponent->BindAction("Jump", IE_Released, this, &AGreyboxTestCharacter::StopJumpAction);
	}
}

void AGreyboxTestCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Placeholder hook for replication-side setup (e.g. role checks before movement).
	if (UCharacterMovementComponent* Move = GetCharacterMovement())
	{
		Move->MaxWalkSpeed = WalkSpeed;
	}
}

void AGreyboxTestCharacter::MoveForward(const float Value)
{
	if (Controller && !FMath::IsNearlyZero(Value))
	{
		const FRotator YawRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AGreyboxTestCharacter::MoveRight(const float Value)
{
	if (Controller && !FMath::IsNearlyZero(Value))
	{
		const FRotator YawRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AGreyboxTestCharacter::JumpAction()
{
	Jump();
}

void AGreyboxTestCharacter::StopJumpAction()
{
	StopJumping();
}

void AGreyboxTestCharacter::LogMovementState(const float DeltaTime)
{
	if (DebugLogInterval <= 0.0f)
	{
		return;
	}

	LastDebugLogTime += DeltaTime;
	if (LastDebugLogTime < DebugLogInterval)
	{
		return;
	}
	LastDebugLogTime = 0.0f;

	if (const UCharacterMovementComponent* Move = GetCharacterMovement())
	{
		const FString State = FString::Printf(
			TEXT("[Greybox] speed=%.1f ground=%d mode=%s"),
			Move->Velocity.Size2D(),
			Move->IsMovingOnGround() ? 1 : 0,
			*UEnum::GetValueAsString(Move->MovementMode));
		UE_LOG(LogTemp, Log, TEXT("%s"), *State);
	}
}
