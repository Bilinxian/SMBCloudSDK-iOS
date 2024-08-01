//
//  SMBCloudSDKMicrophoneCapability.h
//  Pods
//
//  Created by yishuqi on 2024/3/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @brief 麦克风能力集
 */
@interface SMBCloudSDKMicrophoneCapability : NSObject

/**@brief 是否支持静音**/
@property (nonatomic, readonly) BOOL isSupportMute;
/**@brief 是否支持音量调节**/
@property (nonatomic, readonly) BOOL isSupportVolume;
/**@brief 是否支持噪音消除**/
@property (nonatomic, readonly) BOOL isSupportNoiseCancelling;
/**@brief 是否支持回声抑制**/
@property (nonatomic, readonly) BOOL isSupportEchoCancelling;
/**@brief 是否支持电话**/
@property (nonatomic, readonly) BOOL isSupportCall;
/**@brief 采样率，单位为kHz，用于对讲功能（作为对讲参数时需要乘以1000）**/
@property (nonatomic, copy, readonly) NSArray<NSNumber *> *samplingRate;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
