//
//  SMBCloudSDKPlayerFinishInfo.h
//  Pods
//
//  Created by yuanwq on 2023/10/24.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerDefines.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 播放结束原因
 *
 */
@interface SMBCloudSDKPlayerFinishInfo : NSObject

/**
 * @brief 播放停止原因
 * @see SMBCloudSDKPlayerFinishReason
 */

@property (nonatomic, readonly) SMBCloudSDKPlayerFinishReason channelFinishReason;

/**
 * @brief 播放停止错误码
 *
 */
@property (nonatomic, readonly) NSInteger channelFinishCode;

/**
 * @brief 是否需要重试
 */

@property (nonatomic, readonly) BOOL needRetry;

/**
 * @brief 是否显示错误码
 *
 */
@property (nonatomic, readonly) BOOL showErrCode;

/**
 * @brief 错误信息
 *
 */
@property (nonatomic, copy, readonly) NSString *message;

@end

NS_ASSUME_NONNULL_END
