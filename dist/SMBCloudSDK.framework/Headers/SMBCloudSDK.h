//
//  SMBCloudSDK.h
//  SMBCloudSDK
//
//  Created by Li Weijian on 2023/5/12.
//

#import <Foundation/Foundation.h>

//! Project version number for SMBCloudSDK.
FOUNDATION_EXPORT double SMBCloudSDKVersionNumber;

//! Project version string for SMBCloudSDK.
FOUNDATION_EXPORT const unsigned char SMBCloudSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SMBCloudSDK/PublicHeader.h>

// MARK: SMBCloudSDK
#import <SMBCloudSDK/SMBSDKContext.h>

// MARK: SMBCloudSDKBase
#import <SMBCloudSDK/SMBCloudSDKError.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceType.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceFailInfo.h>

// MARK: - DeviceListModule
#import <SMBCloudSDK/SMBCloudSDKDevice.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceEnum.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceListFilterAndParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceListFilterOrParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceListSortType.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceListManager.h>
#import <SMBCloudSDK/SMBCloudSDKChannelDevice.h>

// MARK: - PreviewPlaybackModule
#import <SMBCloudSDK/SMBCloudSDKPlayerAllStatus.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerTalkStatus.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerFinishInfo.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerDefines.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerDelegate.h>
#import <SMBCloudSDK/SMBCloudSDKPreviewManager.h>
#import <SMBCloudSDK/SMBCloudSDKPreviewManagerDefines.h>
#import <SMBCloudSDK/SMBCloudSDKPlaybackManager.h>
#import <SMBCloudSDK/SMBCloudSDKPlaybackEvent.h>
#import <SMBCloudSDK/SMBCloudSDKPlaybackParams.h>
#import <SMBCloudSDK/SMBCloudSDKPlaybackManagerDefines.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceCapability.h>
#import <SMBCloudSDK/SMBCloudSDKPTZCapability.h>
#import <SMBCloudSDK/SMBCloudSDKMotorCapability.h>
#import <SMBCloudSDK/SMBCloudSDKPresetInfo.h>
#import <SMBCloudSDK/SMBCloudSDKFishEyeCapability.h>
#import <SMBCloudSDK/SMBCloudSDKPlaybackScaleInfo.h>
#import <SMBCloudSDK/SMBCloudSDKMicrophoneCapability.h>
#import <SMBCloudSDK/SMBCloudSDKMicrophoneConfig.h>
#import <SMBCloudSDK/SMBCloudSDKSpeakerCapability.h>
#import <SMBCloudSDK/SMBCloudSDKSpeakerConfig.h>
#import <SMBCloudSDK/SMBCloudSDKTalkCapability.h>

// MARK: - DeviceSettingModule
#import <SMBCloudSDK/SMBCloudSDKDeviceSettingManager.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceSDInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDCapability.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDEnum.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDCoordinate.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDInfoParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDLabelInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDFont.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDWatermarkInfo.h>

// MARK: DeviceAddModule
#import <SMBCloudSDK/SMBCloudSDKDeviceAddManager.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceAddEnumDefines.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceForScanList.h>
#import <SMBCloudSDK/SMBCloudSDKOnboardWiFiInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceBindStatusInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceAddNVRChannelInfo.h>

// MARK: RegionModule
#import <SMBCloudSDK/SMBCloudSDKRegionManager.h>
#import <SMBCloudSDK/SMBCloudSDKRegion.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOverview.h>
