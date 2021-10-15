// "ItsRip Example Interactable Project - https://discord.gg/tEAdputpUd "


#include "Interactable_Base.h"
#include "Components/WidgetComponent.h"


void AInteractable_Base::AddWidgetToViewport()
{
	if (WidgetToSpawn)
	{
		APlayerController* PC =  GetWorld()->GetFirstPlayerController();
		if (!PC) return;

		Widget = CreateWidget(GetWorld(), WidgetToSpawn);

		if (!Widget) return;
		Widget->AddToViewport();
		EnableMouseForMenu();
	}
}

void AInteractable_Base::EnableMouseForMenu()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();

	if (!PC) return;

	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PC->SetInputMode(InputMode);
	PC->bShowMouseCursor = true;
}

void AInteractable_Base::DisableMouseForGame()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();

	if (!PC) return;

	const FInputModeGameOnly InputMode;
	PC->SetInputMode(InputMode);
	PC->bShowMouseCursor = false;
	Widget->RemoveFromViewport();
	Widget = nullptr;
}

// Called when the game starts or when spawned
void AInteractable_Base::BeginPlay()
{
	Super::BeginPlay();
}