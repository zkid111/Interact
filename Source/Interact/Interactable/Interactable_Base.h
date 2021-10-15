// ItsRip Example Interactable Project - https://discord.gg/tEAdputpUd

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable_Base.generated.h"


UCLASS()
class INTERACT_API AInteractable_Base : public AActor
{
	GENERATED_BODY()

public:	
	void AddWidgetToViewport();

	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void EnableMouseForMenu(); //This will make it so the player can't move around and will be able to click buttons in the widget.

	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void DisableMouseForGame(); //This will revert the mouse and keyboard back to game settings

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable", meta = (AllowPrivateAccess = true))
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable", meta = (AllowPrivateAccess = true))
	FString ItemBio;

	UPROPERTY()
	UUserWidget* Widget;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	TSubclassOf<UUserWidget> WidgetToSpawn;
	
	UFUNCTION(BlueprintCallable, Category = "Interactable")
	FString GetItemName() const { return ItemName; }

	UFUNCTION(BlueprintCallable, Category = "Interactable")
	FString GetItemBio() const { return ItemBio; }
};
