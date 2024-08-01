//
//  SMBCloudSDKSpeakerConfig.h
//  Pods
//
//  Created by yishuqi on 2024/2/23.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKPreviewManagerDefines.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 扬声器配置
 *
 */
@interface SMBCloudSDKSpeakerConfig : NSObject

/**@brief 是否开启静音**/
@property (nonatomic, assign) BOOL isMuteOn;
/**@brief 当前音量，范围在 0-100 **/
@property (nonatomic, assign) NSInteger volume;
/**@brief 当前选择的输出设备类型**/
@property (nonatomic, assign) SMBCloudSDKSpeakerOutputDeviceType currentOutputDeviceType;

@end

NS_ASSUME_NONNULL_END
