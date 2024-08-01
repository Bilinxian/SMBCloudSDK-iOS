//
//  SMBCloudSDKPlaySpeedCapability.h
//  Pods
//
//  Created by yishuqi on 2024/3/14.
//

NS_ASSUME_NONNULL_BEGIN
/**
 * @brief 播放倍速信息
 */
@interface SMBCloudSDKPlaybackScaleInfo : NSObject

/**@brief 播放倍速的分子**/
@property (nonatomic, readonly) NSInteger numerator;
/**@brief 播放倍速的分母**/
@property (nonatomic, readonly) NSInteger denominator;
/**@brief 播放倍速标题**/
@property (nonatomic, copy, readonly) NSString *speedTitle;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
