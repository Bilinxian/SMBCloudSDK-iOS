//
//  SMBCloudSDKMicrophoneConfig.h
//  Pods
//
//  Created by yishuqi on 2024/2/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 麦克风配置
 *
 */
@interface SMBCloudSDKMicrophoneConfig : NSObject

/**@brief 是否开启静音**/
@property (nonatomic, assign) BOOL isMuteOn;
/**@brief 当前音量，范围在 0-100 **/
@property (nonatomic, assign) NSInteger volume;
/**@brief 噪音消除功能是否开启**/
@property (nonatomic, assign) BOOL isNoiseCancellingOn;
/**@brief 回声抑制是否开启**/
@property (nonatomic, assign) BOOL isEchoCancellingOn;

@end

NS_ASSUME_NONNULL_END
