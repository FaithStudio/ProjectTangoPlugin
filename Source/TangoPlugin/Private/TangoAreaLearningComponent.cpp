/*Copyright 2016 Google
Author: Opaque Media Group
 
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.*/

#include "TangoPluginPrivatePCH.h"
#include "TangoAreaLearningComponent.h"
#include "TangoDevice.h"

bool UTangoAreaLearningComponent::DeleteAreaDescription(FString UUID)
{
	if (UTangoDevice::Get().GetTangoDeviceAreaLearningPointer())
	{
		return UTangoDevice::Get().GetTangoDeviceAreaLearningPointer()->DeleteAreaDescription(UUID);
	}
	else
	{
		UE_LOG(TangoPlugin, Warning, TEXT("UTangoAreaLearningComponent::DeleteAreaDescription: Tango Area Learning not enabled"));
		return false;
	}
}

bool UTangoAreaLearningComponent::IsLearningModeEnabled()
{
	return UTangoDevice::Get().IsLearningModeEnabled();
}

FTangoAreaDescription UTangoAreaLearningComponent::SaveCurrentArea(FString Filename, bool& bIsSuccessful)
{
	if (UTangoDevice::Get().GetTangoDeviceAreaLearningPointer())
	{
     	return UTangoDevice::Get().GetTangoDeviceAreaLearningPointer()->SaveCurrentArea(Filename, bIsSuccessful);
	}
	else
	{
		UE_LOG(TangoPlugin, Warning, TEXT("UTangoAreaLearningComponent::SaveCurrentArea: Tango Area Learning not enabled"));
        bIsSuccessful = false;
		return FTangoAreaDescription();
	}

}

FTangoAreaDescriptionMetaData UTangoAreaLearningComponent::GetMetaData(FTangoAreaDescription AreaDescription, bool& bIsSuccessful)
{
	UE_LOG(TangoPlugin, Log, TEXT("UTangoAreaLearningComponent::GetMetaData: Starting metadata get."));

	return UTangoDevice::Get().GetMetaData(AreaDescription.UUID, bIsSuccessful);
}


void UTangoAreaLearningComponent::SaveMetaData(FTangoAreaDescription AreaDescription, FTangoAreaDescriptionMetaData NewMetadata, bool& bIsSuccessful)
{
	UE_LOG(TangoPlugin, Log, TEXT("UTangoAreaLearningComponent::SaveMetaData: Starting metadata save."));
    UTangoDevice::Get().SaveMetaData(AreaDescription.UUID, NewMetadata, bIsSuccessful);
	return;
}

void UTangoAreaLearningComponent::ImportADF(FString Filepath, bool& bIsSuccessful)
{
	UE_LOG(TangoPlugin, Log, TEXT("UTangoAreaLearningComponent::ImportADF: Starting Area import."));

	UTangoDevice::Get().ImportCurrentArea(Filepath, bIsSuccessful);
}

void UTangoAreaLearningComponent::ExportADF(FString UUID, FString Filepath, bool& bIsSuccessful)
{
	UE_LOG(TangoPlugin, Log, TEXT("UTangoAreaLearningComponent::ExportADF: Starting area export."));

	UTangoDevice::Get().ExportCurrentArea(UUID, Filepath, bIsSuccessful);
}
