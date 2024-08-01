//
//  SMBCloudSDKPreviewManager.h
//  Pods
//
//  Created by Li Weijian on 2023/9/23.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKError.h>
#import <SMBCloudSDK/SMBCloudSDKDevice.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerDelegate.h>
#import <SMBCloudSDK/SMBCloudSDKPTZCapability.h>
#import <SMBCloudSDK/SMBCloudSDKMotorCapability.h>
#import <SMBCloudSDK/SMBCloudSDKPreviewManagerDefines.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerStreamParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceCapability.h>
#import <SMBCloudSDK/SMBCloudSDKPresetInfo.h>
#import <SMBCloudSDK/SMBCloudSDKFishEyeCapability.h>
#import <SMBCloudSDK/SMBCloudSDKMicrophoneCapability.h>
#import <SMBCloudSDK/SMBCloudSDKMicrophoneConfig.h>
#import <SMBCloudSDK/SMBCloudSDKSpeakerCapability.h>
#import <SMBCloudSDK/SMBCloudSDKSpeakerConfig.h>
#import <SMBCloudSDK/SMBCloudSDKTalkCapability.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^SMBCloudSDKPreviewManagerCallback)(__kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKPreviewManagerGetStreamUrlCallback)(__kindof SMBCloudSDKError * error, NSString * streamUrl);
typedef void (^SMBCloudSDKPreviewGetDeviceCapabilityCallback)(SMBCloudSDKDeviceCapability * _Nullable deviceCapability, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPreviewGetFocusCapabilityCallback)(BOOL isSupportFocus, NSArray<NSNumber *> * minimumFocalLengthRange, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPreviewManagerGetPtzCapabilityCallback)(SMBCloudSDKPTZCapability * _Nullable capability, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPreviewManagerGetMotorCapabilityCallback)(SMBCloudSDKMotorCapability * _Nullable capability, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPreviewManagerGetAllPresetCallback)(NSArray<SMBCloudSDKPresetInfo *> * presetArray, __kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKPreviewManagerGetCameraMaskEnableCallback)(BOOL isCameraMaskEnabled, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPreviewManagerSwitchTypeCallback)(SMBCloudSDKScreenFlipType flipType, SMBCloudSDKScreenRotateType rotateType, __kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKPreviewGetFishEyeCapabilityCallback)(SMBCloudSDKFishEyeCapability * _Nullable fishEyeCapability, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPreviewMicrophoneCapabilityCallback)(SMBCloudSDKMicrophoneCapability * _Nullable microphoneCapability, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPreviewMicrophoneConfigCallback)(SMBCloudSDKMicrophoneConfig * config, __kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKPreviewSpeakerCapabilityCallback)(SMBCloudSDKSpeakerCapability * _Nullable speakerCapability, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPreviewSpeakerConfigCallback)(SMBCloudSDKSpeakerConfig * config, __kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKPreviewTalkCapabilityCallback)(SMBCloudSDKTalkCapability * _Nullable talkCapability, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPreviewManualAlarmCallback)(NSInteger countdown, __kindof SMBCloudSDKError *error);

@interface SMBCloudSDKPreviewManager : NSObject

/**
 * @brief 预览播放器播放状态回调
 * @see SMBCloudSDKPlayerPlayDelegate
 */
@property (nonatomic, weak, nullable) id<SMBCloudSDKPlayerPlayDelegate> playerDelegate;
/**
 * @brief 预览播放器截图状态回调
 * @see SMBCloudSDKPlayerSnapshotDelegate
 */
@property (nonatomic, weak, nullable) id<SMBCloudSDKPlayerSnapshotDelegate> snapshotDelegate;
/**
 * @brief 预览播放器录像状态回调
 * @see SMBCloudSDKPlayerRecordDelegate
 *
 */
@property (nonatomic, weak, nullable) id<SMBCloudSDKPlayerRecordDelegate> recordDelegate;

- (instancetype)init NS_UNAVAILABLE;
/**
 * @brief 初始化方法
 * @param deviceParam 设备参数
 * @see SMBCloudSDKDeviceParam
 *
 */
- (instancetype)initWithDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam;

/**
 * @brief 获取预览音视频流访问地址
 * @discussion 错误码： -82400(参数错误) -80731（token过期或不存在）
 * @param resolution 清晰度
 * @see SMBCloudSDKPlayerResolution
 * @param callback 请求结束后回调，参数：1. 请求错误信息  2. 音视频流地址
 */
- (void)requestPreviewStreamUrlWithResolution:(SMBCloudSDKPlayerResolution)resolution
                                     callback:(SMBCloudSDKPreviewManagerGetStreamUrlCallback)callback;

/**
 * @brief 获取对讲音频流访问地址
 * @discussion 错误码： -82400(参数错误) -80731（token过期或不存在）
 * @param callback 请求结束后回调，参数：1. 请求错误信息  2. 音频流地址
 */
- (void)requestSpeechStreamUrlWithCallback:(SMBCloudSDKPreviewManagerGetStreamUrlCallback)callback;

/**
 * @brief 获取IPC的设备能力集
 *
 * @param callback 结果回调 （SMBCloudSDKDeviceCapability (设备能力集对象, 若请求失败，则该值为nil)，SMBCloudSDKError（请求返回的错误信息））
 *
 */
- (void)reqGetIPCDeviceCapabilityWithCallback:(SMBCloudSDKPreviewGetDeviceCapabilityCallback)callback;

/**
 * @brief 获取NVR的设备能力集
 * @discussion 仅NVR通道可用
 *
 * @param callback 结果回调 （SMBCloudSDKDeviceCapability (设备能力集对象, 若请求失败，则该值为nil)，SMBCloudSDKError（请求返回的错误信息））
 *
 */
- (void)reqGetNVRDeviceCapabilityWithCallback:(SMBCloudSDKPreviewGetDeviceCapabilityCallback)callback;

#pragma mark - 鱼眼能力集
/**
 * @brief 获取鱼眼设备能力集
 *
 * @param callback 结果回调 （SMBCloudSDKFishEyeCapability (鱼眼能力集对象, 若请求失败，则该值为nil)，SMBCloudSDKError（请求返回的错误信息））
 *
 */
- (void)reqGetFishEyeCapabilityWithCallback:(SMBCloudSDKPreviewGetFishEyeCapabilityCallback)callback;

#pragma mark - 云台能力集
/**
 * @brief 获取设备的云台能力集
 *
 * @param callback 结果回调，参数：1. 云台能力集对象ptzCapability (若请求失败，该值为nil)；2. 请求错误信息
 * @see SMBCloudSDKPTZCapability
 *
 */
- (void)reqGetPtzCapabilityWithCallback:(SMBCloudSDKPreviewManagerGetPtzCapabilityCallback)callback;

/**
 * @brief 获取设备的旧版云台能力集
 *
 * @param callback 结果回调，参数：1. 旧版云台能力集对象motorCapability (若请求失败，该值为nil)；2. 请求错误信息
 * @see SMBCloudSDKMotorCapability
 *
 */
- (void)reqGetMotorCapabilityWithCallback:(SMBCloudSDKPreviewManagerGetMotorCapabilityCallback)callback;

#pragma mark - 获取调焦能力集
/**
 * @brief 获取设备的调焦能力集
 * @param callback 结果回调，参数：1. 是否支持聚焦；2. 支持聚焦功能的机型的最小焦距合法取值范围，单位为cm；3. 请求错误信息
 *
 */
- (void)reqGetPtzFocusCapabilityWithCallback:(SMBCloudSDKPreviewGetFocusCapabilityCallback)callback;

#pragma mark - 云台复位
/**
 * @brief 云台复位
 *
 * @param speed 云台转动的速度
 * @see SMBCloudSDKPtzSpeed
 * @param callback 结果回调，参数：1. 请求错误信息
 * @discussion 若云台能力集ptzCapability或motorCapability中calibrate_supported字段为0或者没有该字段，则该方法无效。目前只支持NVR通道、单目IPC、多目IPC的通道1
 *
 */
- (void)reqResetPtzWithSpeed:(SMBCloudSDKPtzSpeed)speed
                    callback:(SMBCloudSDKPreviewManagerCallback)callback;

#pragma mark - 云台转动、扫描
/**
 * @brief 云台转动
 *
 * @param direction: 云台转动的方向
 * @see SMBCloudSDKPtzRotateDirection
 * @param speed 云台转动的速度
 * @see SMBCloudSDKPtzSpeed
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqPtzRotateByDirection:(SMBCloudSDKPtzRotateDirection)direction
                          speed:(SMBCloudSDKPtzSpeed)speed
                       callback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 云台停止转动
 *
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqPtzStopWithCallback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 云台扫描
 *
 * @param speed 云台转动的速度
 * @see SMBCloudSDKPtzSpeed
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqPtzScanWithSpeed:(SMBCloudSDKPtzSpeed)speed
                   callback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 云台调焦
 *
 * @param focus 聚焦的地方：近处、远处、停止
 * @see SMBCloudSDKPtzFocus
 * @param speed 云台调焦的速度
 * @see SMBCloudSDKPtzSpeed
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqPtzFocusTo:(SMBCloudSDKPtzFocus)focus
                speed:(SMBCloudSDKPtzSpeed)speed
             callback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 通过设备参数识别设备，停止云台调焦
 *
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqPtzStopFocusWithCallback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 云台变倍
 *
 * @param zoom 如何变倍：扩大、缩小
 * @see SMBCloudSDKPtzZoom
 * @param speed 云台变倍的速度
 * @see SMBCloudSDKPtzSpeed
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqPtzZoomTo:(SMBCloudSDKPtzZoom)zoom
               speed:(SMBCloudSDKPtzSpeed)speed
            callback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 通过设备参数识别设备，停止云台变倍
 *
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqPtzStopZoomWithCallback:(SMBCloudSDKPreviewManagerCallback)callback;


#pragma mark - 预置点
/**
 * @brief 获取所有预置点信息
 *
 * @param callback 结果回调，参数：1. 预置点数组，代表该设备的所有预置点。若请求失败，则为空数组；2. 请求错误信息
 *
 */
- (void)reqGetAllPresetsWithCallback:(SMBCloudSDKPreviewManagerGetAllPresetCallback)callback;

/**
 * @brief 运动到预置点
 * @param presetId 预置点Id，可由reqGetAllPresetsWithCallback接口获取
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqExecutePresetWithPresetId:(NSString *)presetId
                            callback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 删除预置点
 * @param presetId 预置点Id，可由reqGetAllPresetsWithCallback接口获取
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqDeletePresetWithPresetId:(NSString *)presetId
                           callback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 新增或修改预置点
 * @param presetId 预置点Id，取值范围是[1, maxPresets]：如果设备遵循ptz协议，则maxPresets由ptz能力集中的maxPresetPoints决定；若只遵循motor协议，则无法获知最大预置点数目，一般取默认值300。当设置的预置点id大于其最大取值会请求失败。若 presetId == -1或该 id 对应的预置点未设置，则新建一个预置点，否则修改此预置点。
 * @see SMBCloudSDKPTZCapability
 * @param isOverride 修改预置点时是否覆盖预置点位置信息。
 * @param presetName 预置点名称，如果不指定，则使用系统自动生成的名称。
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqOperatePresetWithPresetId:(NSString *)presetId
                          isOverride:(BOOL)isOverride
                          presetName:(NSString *)presetName
                            callback:(SMBCloudSDKPreviewManagerCallback)callback;

#pragma mark - 镜头遮蔽
/**
 * @brief 获取镜头遮蔽状态
 *
 * @param callback 结果回调，参数：1. 设备是否开启了镜头遮蔽（true代表开启，false代表未开启）。若请求失败，该值为false；2. 请求错误信息
 *
 */
- (void)reqGetCameraMaskInfoWithCallback:(SMBCloudSDKPreviewManagerGetCameraMaskEnableCallback)callback;

/**
 * @brief 打开镜头遮蔽
 *
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqOpenCameraMaskWithCallback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 关闭镜头遮蔽
 *
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqCloseCameraMaskWithCallback:(SMBCloudSDKPreviewManagerCallback)callback;

#pragma mark - 镜头镜像、画面旋转状态
/**
 * @brief 通过设备参数识别设备，获取镜头镜像、画面旋转状态
 *
 * @param deviceParam 设备参数
 * @see SMBCloudSDKDeviceParam
 * @param callback 结果回调，参数：1. 镜头镜像状态，若请求失败，该值为SMBCloudSDKScreenFlipTypeClose；2. 画面旋转状态，若请求失败，该值为SMBCloudSDKScreenRotateTypeClose；3. 请求错误信息
 *
 */
- (void)reqGetSwitchTypeWithCallback:(SMBCloudSDKPreviewManagerSwitchTypeCallback)callback;

/**
 * @brief 通过设备参数识别设备，设置镜头镜像、画面旋转状态
 *
 * @param deviceParam 设备参数
 * @see SMBCloudSDKDeviceParam
 * @param flipType 镜头镜像状态
 * @see SMBCloudSDKScreenFlipType
 * @param rotateType 画面旋转状态
 * @see SMBCloudSDKScreenRotateType
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqSetSwitchTypeWithFlipType:(SMBCloudSDKScreenFlipType)flipType
                          rotateType:(SMBCloudSDKScreenRotateType)rotateType
                            callback:(SMBCloudSDKPreviewManagerCallback)callback;

#pragma mark - 监控点报警
/**
 * @brief 手动触发报警输出
 * @discussion 本接口声光分离和声光不分离设备都可用
 *
 * @param callback 结果回调，参数：1. 设备端报警倒计时的时长，单位为秒，若请求失败，该值为0；2. 请求错误信息
 *
 */
- (void)reqTriggerManualAlarmWithCallback:(SMBCloudSDKPreviewManualAlarmCallback)callback;

/**
 * @brief 手动触发声光分离设备的报警输出
 * @discussion 只有设备能力集的isSupportSeperateManualMsgAlarm为true时才可使用
 * @see SMBCloudSDKDeviceCapability
 *
 * @param alarmType 手动报警类型，只有设备能力集SMBCloudSDKDeviceCapability中的msgAlarmSeperateList包含该类型时才有意义
 * @see SMBCloudSDKDeviceCapability
 * @see SMBCloudSDKMsgAlarmType
 * @param lightType 光报警类型，只有设备能力集SMBCloudSDKDeviceCapability中的msgAlarmSeperateList包含SMBCloudSDKMsgAlarmTypeLight时有意义
 * @see SMBCloudSDKDeviceCapability
 * @see SMBCloudSDKMsgAlarmLightType
 * @param callback 结果回调，参数：1. 设备端报警倒计时的时长，单位为秒，若请求失败，该值为0；2. 请求错误信息
 *
 */
- (void)reqTriggerManualAlarmWithAlarmType:(SMBCloudSDKMsgAlarmType)alarmType
                                 lightType:(SMBCloudSDKMsgAlarmLightType)lightType
                                  callback:(SMBCloudSDKPreviewManualAlarmCallback)callback;

/**
 * @brief 手动关闭报警
 *
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqTurnOffManualAlarmWithCallback:(SMBCloudSDKPreviewManagerCallback)callback;

#pragma mark - 麦克风
/**
 * @brief 获取麦克风能力集
 * @discussion 设备能力集存在audio字段，且取值包含microphone时才支持
 * @param callback 结果回调，参数：1. 麦克风能力集，若请求失败，该值为nil；2. 请求错误信息
 * @see SMBCloudSDKMicrophoneCapability
 *
 */
- (void)reqMicrophoneCapabilityWithCallback:(SMBCloudSDKPreviewMicrophoneCapabilityCallback)callback;


/**
 * @brief 获取麦克风配置
 * @discussion 设备能力集存在audio字段，且取值包含microphone时才支持
 * @param callback 结果回调，参数：1. 麦克风配置，若请求失败，返回默认配置；2. 请求错误信息
 * @see SMBCloudSDKMicrophoneConfig
 *
 */
- (void)reqGetMicrophoneConfigWithCallback:(SMBCloudSDKPreviewMicrophoneConfigCallback)callback;


/**
 * @brief 设置麦克风音量
 * @discussion 麦克风能力集中的isSupportVolume为true才支持
 * @see SMBCloudSDKMicrophoneCapability
 * @param volume: 麦克风音量，范围为0-100
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqSetMicrophoneConfigWithVolume:(NSInteger)volume
                                callback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 设置麦克风静音状态
 * @discussion 麦克风能力集中的isSupportMute为true才支持
 * @see SMBCloudSDKMicrophoneCapability
 * @param mute: 是否开启静音：YES开启，NO关闭
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqSetMicrophoneConfigWithMute:(BOOL)isMuteOn
                              callback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 设置麦克风的噪音消除状态
 * @discussion 麦克风能力集中的isSupportNoiseCancelling为true才支持
 * @see SMBCloudSDKMicrophoneCapability
 * @param noiseCancelling: 是否开启噪音消除：YES开启，NO关闭
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqSetMicrophoneConfigWithNoiseCancelling:(BOOL)isNoiseCancellingOn
                                         callback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 设置麦克风的回声抑制状态
 * @discussion 麦克风能力集中的isSupportEchoCancelling为true才支持
 * @see SMBCloudSDKMicrophoneCapability
 * @param echoCancelling: 是否开启回声抑制：YES开启，NO关闭
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqSetMicrophoneConfigWithEchoCancelling:(BOOL)isEchoCancellingOn
                                        callback:(SMBCloudSDKPreviewManagerCallback)callback;


#pragma mark - 扬声器
/**
 * @brief 获取扬声器能力集
 * @discussion 设备能力集存在audio字段，且取值包含speaker时才支持
 * @param callback 结果回调，参数：1. 扬声器能力集，若请求失败，该值为nil；2. 请求错误信息
 * @see SMBCloudSDKSpeakerCapability
 *
 */
- (void)reqSpeakerCapabilityWithCallback:(SMBCloudSDKPreviewSpeakerCapabilityCallback)callback;


/**
 * @brief 获取扬声器配置
 * @discussion 设备能力集存在audio字段，且取值包含speaker时才支持
 * @param callback 结果回调，参数：1. 扬声器配置，若请求失败，返回默认配置；2. 请求错误信息
 * @see SMBCloudSDKSpeakerConfig
 *
 */
- (void)reqGetSpeakerConfigWithCallback:(SMBCloudSDKPreviewSpeakerConfigCallback)callback;


/**
 * @brief 设置扬声器音量
 * @discussion 扬声器能力集中的isSupportVolume为true时才支持
 * @see SMBCloudSDKSpeakerCapability
 * @param volume: 扬声器音量，范围在0-100
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqSetSpeakerConfigWithVolume:(NSInteger)volume
                             callback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 设置扬声器静音
 * @discussion 扬声器能力集中的isSupportMute为true时才支持
 * @see SMBCloudSDKSpeakerCapability
 * @param mute: 扬声器静音状态，YES为打开，NO为关闭
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqSetSpeakerConfigWithMute:(BOOL)isMuteOn
                           callback:(SMBCloudSDKPreviewManagerCallback)callback;

/**
 * @brief 设置扬声器输出设备类型
 * @discussion 扬声器能力集的supportedOutputDeviceTypes不为.unsupport，或扬声器能力集的isSupportAllOutputDeviceTypes为true
 * @see SMBCloudSDKSpeakerCapability
 * @param outputDeviceType: 输出设备类型
 * @discussion 必须包含在扬声器能力集的supportedOutputDeviceTypes中，或扬声器能力集的isSupportAllOutputDeviceTypes为true
 * @see SMBCloudSDKSpeakerOutputDeviceType
 * @param callback 结果回调，参数：1. 请求错误信息
 *
 */
- (void)reqSetSpeakerConfigWithOutputDeviceType:(SMBCloudSDKSpeakerOutputDeviceType)outputDeviceType
                                       callback:(SMBCloudSDKPreviewManagerCallback)callback;

#pragma mark - 对讲
/**
 * @brief 获取对讲能力集
 * @param callback 结果回调，参数：1. 对讲能力集，若请求失败，该值为nil；2. 请求错误信息
 * @see SMBCloudSDKTalkCapability
 *
 */
- (void)reqTalkCapabilityWithCallback:(SMBCloudSDKPreviewTalkCapabilityCallback)callback;


@end

@interface SMBCloudSDKPreviewManager (Player)

/**
 * @brief 获取预览播放器播放状态
 * @return 预览播放器播放状态
 * @see SMBCloudSDKPlayerPlayStatus
 */
- (SMBCloudSDKPlayerPlayStatus *)currentPlayStatus;
/**
 * @brief 获取预览播放器音量状态
 * @return 预览播放器音量状态
 * @see SMBCloudSDKPlayerVolumeStatus
 */
- (SMBCloudSDKPlayerVolumeStatus *)currentVolumeStatus;
/**
 * @brief 获取预览播放器截图状态
 * @return 预览播放器截图状态
 * @see SMBCloudSDKPlayerSnapshotStatus
 */
- (SMBCloudSDKPlayerSnapshotStatus *)currentSnapshotStatus;
/**
 * @brief 获取预览播放器录像状态
 * @return 预览播放器录像状态
 * @see SMBCloudSDKPlayerRecordStatus
 */
- (SMBCloudSDKPlayerRecordStatus *)currentRecordStatus;

/**
 * @brief 开始预览
 * @param param 预览音视频流参数
 * @see SMBCloudSDKPlayerStreamParam
 */
- (void)startPreviewWithStreamParam:(SMBCloudSDKPlayerStreamParam *)param;
/**
 * @brief 停止播放
 * @param error 停止错误码，一般传入0即可
 */
- (void)stopWithError:(NSInteger)error
NS_SWIFT_NAME(stop(error:));
/**
 * @brief 暂停播放
 */
- (void)pause;
/**
 * @brief 回复播放
 */
- (void)resume;
/**
 * @brief 设置解码模式
 * @param mode 解码模式
 * @see SMBCloudSDKPlayerDecodeMode
 */
- (void)setDecodeMode:(SMBCloudSDKPlayerDecodeMode)mode
NS_SWIFT_NAME(setDecodeMode(mode:));
/**
 * @brief 开始录像
 * @param path 录像目标路径
 */
- (void)startRecord:(NSString *)path
NS_SWIFT_NAME(startRecord(path:));
/**
 * @brief 停止录像
 */
- (void)stopRecord;
/**
 * @brief 截图
 * @param url 截图目标路径
 */
- (void)screenShotWithUrl:(NSString *)url
NS_SWIFT_NAME(screenShot(url:));
/**
 * @brief 截图
 * @param url 截图目标路径
 * @param type 截图类型
 * @see SMBCloudSDKPlayerSnapshotType
 */
- (void)screenShotWithUrl:(NSString *)url picType:(SMBCloudSDKPlayerSnapshotType)type
NS_SWIFT_NAME(screenShot(url:type:));
/**
 * @brief 设置音量
 * @param volume 音量
 */
- (void)setVolume:(NSInteger)volume
NS_SWIFT_NAME(setVolme(volume:));
/**
 * @brief 开始对讲
 */
- (void)startSpeech;
/**
 * @brief 停止对讲
 */
- (void)stopSpeech;
/**
 * @brief 开启麦克风
 * @param mode 对讲模式
 * @see SMBCloudSDKPlayerSpeechMode
 * @param url 音频流地址
 * @param speakerSampleRate 扬声器采样率，单位为Hz
 * @param microphoneSampleRate 麦克风采样率，单位为Hz
 * @param isChannel 是否为通道设备，YES为是，NO则不是
 */
- (void)startMicrophone:(SMBCloudSDKPlayerSpeechMode)mode
                    url:(NSString *)url
      speakerSampleRate:(NSArray<NSNumber *> *)speakerSampleRate
   microphoneSampleRate:(NSArray<NSNumber *> *)microphoneSampleRate
              isChannel:(BOOL)isChannel
NS_SWIFT_NAME(startMicrophone(mode:url:speakerSampleRate:microphoneSampleRate:isChannel:));
/**
 * @brief 开启麦克风
 * @param mode 对讲模式
 * @see SMBCloudSDKPlayerSpeechMode
 * @param url 音频流地址
 * @param speakerSampleRate 扬声器采样率，单位为Hz
 * @param microphoneSampleRate 麦克风采样率，单位为Hz
 * @param isChannel 是否为通道设备，YES为是，NO则不是
 * @param voiceChange 是否开启变声
 */
- (void)startMicrophone:(SMBCloudSDKPlayerSpeechMode)mode
                    url:(NSString *)url
      speakerSampleRate:(NSArray<NSNumber *> *)speakerSampleRate
   microphoneSampleRate:(NSArray<NSNumber *> *)microphoneSampleRate
              isChannel:(BOOL)isChannel
            voiceChange:(BOOL)voiceChange
NS_SWIFT_NAME(startMicrophone(mode:url:speakerSampleRate:microphoneSampleRate:isChannel:voiceChange:));
/**
 * @brief 停止麦克风
 */
- (void)stopMicrophone;
/**
 * @brief 设置鱼眼视图的展示模式
 *
 * @param mode 指定展示模式
 * @see SMBCloudSDKFishEyeDisplayMode
 */
- (void)setFishEyeDisplayMode:(SMBCloudSDKFishEyeDisplayMode)mode
NS_SWIFT_NAME(setFishEyeDisplayMode(mode:));

/**
 * @brief 设置显示画面样式
 *
 * @param scaleMode 画面拉伸模式
 * @param displayRatio 画面展示比例
 * @param offsetRatio 画面偏移值
 * @see SMBCloudSDKPlayerScaleMode
 */
- (void)setDisplayViewWithScaleMode:(SMBCloudSDKPlayerScaleMode)scaleMode displayRatio:(float)displayRatio verticalOffsetRatio:(float)offsetRatio
NS_SWIFT_NAME(setDisplayView(scaleMode:displayRatio:offsetRatio:));

/**
 * @brief 开启/关闭画面手势
 *
 * @param enable 开启/关闭
 *
 */
- (void)setDisplayViewGLGestureRecognizerEnable:(BOOL)enable
NS_SWIFT_NAME(setDisplayViewGLGestureRecognizer(enable:));

@end

NS_ASSUME_NONNULL_END
