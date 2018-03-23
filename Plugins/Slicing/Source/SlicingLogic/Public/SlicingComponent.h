// Copyright 2018, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "SlicingLogicModule.h"

#include "CoreMinimal.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

#include "SlicingComponent.generated.h"

UCLASS()
class SLICINGLOGIC_API USlicingComponent: public UBoxComponent
{
	GENERATED_BODY()

public:
	/**** The names of the sockets that are also needed by the editor ****/
	static const FName SocketHandleName;
	static const FName SocketBladeName;
	static const FName SocketTipName;
	//* The tag name needed to recognize objects in the world that are cuttable by the Slicing plugin
	static const FName TagCuttable;

public:
	// Sets default values. Called when generated, even in the editor.
	USlicingComponent();

	/**** The implementation of standard component functions ****/
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	//* Needed for the debug option booleans
	FSlicingLogicModule* SlicingLogicModule;
	//* The component of the object, the SlicingComponent is attached to
	UStaticMeshComponent* SlicingObject;
	//* The object that is currently being cut, but did not go through the slicing process yet
	UPrimitiveComponent* CutComponent;

private:
	void DrawComponent();
};