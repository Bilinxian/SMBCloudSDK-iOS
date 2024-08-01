//
//  SMBCloudSDKPlayerTalkStatus.h
//  Pods
//
//  Created by Li Weijian on 2023/10/29.
//
#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerDefines.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @brief 播放器对讲状态
 *
 */
@interface SMBCloudSDKPlayerTalkStatus : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 对讲状态
 * @see SMBCloudSDKPlayerStatus
 */
@property (nonatomic, readonly) SMBCloudSDKPlayerStatus status;
/**
 * @brief 对讲停止原因
 * @see SMBCloudSDKPlayerFinishReason
 */
@property (nonatomic, readonly) SMBCloudSDKPlayerFinishReason finishReason;
/**
 * @brief 对讲停止错误码
 *
 */
@property (nonatomic, readonly) NSInteger finishCode;

@end

NS_ASSUME_NONNULL_END
