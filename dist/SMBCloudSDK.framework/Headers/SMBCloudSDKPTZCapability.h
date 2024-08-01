//
//  SMBCloudSDKPTZCapability.h
//  Pods
//
//  Created by yishuqi on 2024/3/6.
//
#import <SMBCloudSDK/SMBCloudSDKPreviewManagerDefines.h>


NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 云台能力集
 */
@interface SMBCloudSDKPTZCapability : NSObject

- (instancetype)init NS_UNAVAILABLE;

/** @brief 是否支持持续移动 */
@property (nonatomic, readonly) BOOL isSupportContinuousMove;
/**
 * @brief 是否支持水平垂直电机同时移动
 * @discussion 只有为true才支持斜向移动
 */
@property (nonatomic, readonly) BOOL isSupportPanAndTiltMoveSync;
/**
 * @brief 缩放倍数范围
 * @discussion 数组长度为2，每个数范围[0, 1]，为空则不支持变倍
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber *> * zoomRange;
/** @brief 是否支持扫描 */
@property (nonatomic, readonly) BOOL isSupportScan;
/** @brief 是否支持预置点 */
@property (nonatomic, readonly) BOOL isSupportPreset;
/** @brief 最大预置点数目 */
@property (nonatomic, readonly) NSInteger maxPresetPoints;
/** @brief 是否支持手动校准 */
@property (nonatomic, readonly) BOOL isSupportManualCalibrate;

@end

NS_ASSUME_NONNULL_END
