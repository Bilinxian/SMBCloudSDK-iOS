//
//  SMBCloudSDKTalkCapability.h
//  Pods
//
//  Created by yishuqi on 2024/4/25.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKMicrophoneCapability.h>
#import <SMBCloudSDK/SMBCloudSDKSpeakerCapability.h>


NS_ASSUME_NONNULL_BEGIN
/**
 * @brief 对讲能力集
 */
@interface SMBCloudSDKTalkCapability : NSObject

/**@brief 是否支持对讲**/
@property (nonatomic, readonly) BOOL isSupportTalk;
/**
 * @brief 麦克风能力集
 * @see SMBCloudSDKMicrophoneCapability
 */
@property (nonatomic, readonly, copy) SMBCloudSDKMicrophoneCapability * microphoneCapability;
/**
 * @brief 扬声器能力集
 * @see SMBCloudSDKSpeakerCapability
 */
@property (nonatomic, readonly, copy) SMBCloudSDKSpeakerCapability * speakerCapability;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
