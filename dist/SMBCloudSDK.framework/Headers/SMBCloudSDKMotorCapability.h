//
//  SMBCloudSDKMotorCapability.h
//  Pods
//
//  Created by yishuqi on 2024/4/14.
//

#import <SMBCloudSDK/SMBCloudSDKPreviewManagerDefines.h>


NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 云台能力集
 */
@interface SMBCloudSDKMotorCapability : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 是否支持水平垂直电机同时移动
 * @discussion 只有为true才支持斜向移动
 */
@property (nonatomic, readonly) BOOL isSupportPanAndTiltMoveSync;
/** @brief 是否支持预置点 */
@property (nonatomic, readonly) BOOL isSupportPreset;
/** @brief 是否支持手动校准 */
@property (nonatomic, readonly) BOOL isSupportManualCalibrate;

@end

NS_ASSUME_NONNULL_END
