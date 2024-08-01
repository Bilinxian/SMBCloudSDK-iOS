//
//  SMBCloudSDKSpeakerCapability.h
//  Pods
//
//  Created by yishuqi on 2024/3/11.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKPreviewManagerDefines.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @brief 麦克风能力集
 */
@interface SMBCloudSDKSpeakerCapability : NSObject

/**@brief 是否支持静音**/
@property (nonatomic, readonly) BOOL isSupportMute;
/**@brief 是否支持音量调节**/
@property (nonatomic, readonly) BOOL isSupportVolume;
/**
 * @brief 支持的输出设备类型（数据类型为OptionSet，即可能不止一种类型）
 * @see SMBCloudSDKSpeakerOutputDeviceType
 */
@property (nonatomic, readonly) SMBCloudSDKSpeakerOutputDeviceType supportedOutputDeviceTypes;
/**
 * @brief 是否支持所有输出设备类型
 * @discussion 如果 supportedOutputDeviceTypes 不为SMBCloudSDKSpeakerOutputDeviceTypeUnsupport，则该字段无效，即 supportedOutputDeviceTypes 的优先级更高
 **/
@property (nonatomic, readonly) BOOL isSupportAllOutputDeviceTypes;
/**@brief 采样率，单位为kHz，用于对讲功能（作为对讲参数时需要乘以1000）**/
@property (nonatomic, copy, readonly) NSArray<NSNumber *> *samplingRate;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
