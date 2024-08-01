//
//  SMBCloudSDKDeviceCapability.h
//  Pods
//
//  Created by yishuqi on 2024/2/26.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKPreviewManagerDefines.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 设备能力集
 *
 */
@interface SMBCloudSDKDeviceCapability : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**@brief Relay协议，默认支持1.2版本 **/
@property (nonatomic, copy, readonly) NSString *relayVersion;
/**@brief 音视频流版本 **/
@property (nonatomic, copy, readonly) NSString *streamingVersion;
/**
 * @brief 语音操作
 * @see SMBCloudSDKVoiceOperation
 **/
@property (nonatomic, readonly) SMBCloudSDKVoiceOperation supportedVoiceOperation;
/**@brief 是否支持镜头遮蔽**/
@property (nonatomic, readonly) BOOL isSupportLensMask;
/**@brief 是否支持报警输出**/
@property (nonatomic, readonly) BOOL isSupportAlarmOut;
/**@brief 是否支持云台**/
@property (nonatomic, readonly) BOOL isSupportPtz;
/**@brief 是否支持旧版云台**/
@property (nonatomic, readonly) BOOL isSupportMotor;

/**@brief 支持鱼眼**/
@property (nonatomic, readonly) BOOL supportFisheye;
/**@brief 是否支持走廊模式**/
@property (nonatomic) BOOL isSupportCorridorMode;
/**
 * @brief 通道IPC的能力集
 * @see SMBCloudSDKChannelCapability
 **/
@property (nonatomic, readonly) SMBCloudSDKChannelCapability channelCapability;
/**
 * @brief 声光报警不分离(声音报警和光报警，不可单独报警)时支持的报警种类。
 * @see SMBCloudSDKMsgAlarmType
 **/
@property (nonatomic) SMBCloudSDKMsgAlarmType msgAlarmList;
/**
 * @brief 声光报警分离(声音报警和光报警，可以单独报警)时支持的报警种类。
 * @see SMBCloudSDKMsgAlarmType
 **/
@property (nonatomic) SMBCloudSDKMsgAlarmType msgAlarmSeperateList;
/**@brief 是否支持声光分离式报警**/
@property (nonatomic) BOOL isSupportSeperateManualMsgAlarm;

@end

NS_ASSUME_NONNULL_END
