//
//  SMBCloudSDKPlaybackManager.h
//  Pods
//
//  Created by Li Weijian on 2023/9/23.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKError.h>
#import <SMBCloudSDK/SMBCloudSDKDevice.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerDelegate.h>
#import <SMBCloudSDK/SMBCloudSDKPlaybackParams.h>
#import <SMBCloudSDK/SMBCloudSDKPlaybackManagerDefines.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerStreamParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceParam.h>
#import <SMBCloudSDK/SMBCloudSDKPlaybackEvent.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceCapability.h>
#import <SMBCloudSDK/SMBCloudSDKFishEyeCapability.h>
#import <SMBCloudSDK/SMBCloudSDKPlaybackScaleInfo.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^SMBCloudSDKPlaybackManagerCallback)(__kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKPlaybackManagerGetStreamUrlCallback)(__kindof SMBCloudSDKError * error, NSString * streamUrl);
typedef void (^SMBCloudSDKPlaybackVideoDatesCallback)(NSArray<NSDate *> * hasVideoDateList, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPlaybackVideoListCallback)(NSInteger clientID, NSArray<SMBCloudSDKPlaybackEvent *> * eventList, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPlaybackGetDeviceCapabilityCallback)(SMBCloudSDKDeviceCapability * _Nullable deviceCapability, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPlaybackGetFishEyeCapabilityCallback)(SMBCloudSDKFishEyeCapability * _Nullable fishEyeCapability, __kindof SMBCloudSDKError *error);
typedef void (^SMBCloudSDKPlaybackGetScaleInfoListCallback)(NSArray<SMBCloudSDKPlaybackScaleInfo *> * scaleInfoList, __kindof SMBCloudSDKError *error);


@interface SMBCloudSDKPlaybackManager : NSObject

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
 * @brief 获取回放音视频流访问地址
 * @discussion 错误码： -82400(参数错误) -80731（token过期或不存在）
 * @param callback 请求结束后回调，参数：1. 请求错误信息  2. 音视频流地址
 */
- (void)requestPlaybackStreamUrlWithCallback:(SMBCloudSDKPlaybackManagerGetStreamUrlCallback)callback;

/**
 * @brief 获取IPC设备能力集
 *
 * @param callback 结果回调，参数：1. 设备能力集对象，若请求失败，该值为nil；2. 请求返回的错误信息
 *
 */
- (void)reqGetIPCDeviceCapabilityWithCallback:(SMBCloudSDKPlaybackGetDeviceCapabilityCallback)callback;

/**
 * @brief 获取NVR的设备能力集
 * @discussion 仅NVR通道可用
 *
 * @param callback 结果回调 （SMBCloudSDKDeviceCapability (设备能力集对象, 若请求失败，则该值为nil)，SMBCloudSDKError（请求返回的错误信息））
 *
 */
- (void)reqGetNVRDeviceCapabilityWithCallback:(SMBCloudSDKPlaybackGetDeviceCapabilityCallback)callback;

/**
 * @brief 获取鱼眼设备能力集
 *
 * @param callback 结果回调，参数：1. 设备鱼眼能力集对象，若请求失败，该值为nil；2. 请求返回的错误信息
 *
 */
- (void)reqGetFishEyeCapabilityWithCallback:(SMBCloudSDKPlaybackGetFishEyeCapabilityCallback)callback;


/**
 * @brief 搜索设备某一年存在回放录像的日期
 * @param year 搜索回放录像的年份
 * @param callback 结果回调， 参数：1. NSDate数组，代表该设备上存在回放录像的日期；2. 请求错误信息
 */
- (void)reqPlaybackDatesInYear:(NSInteger)year
                      callback:(SMBCloudSDKPlaybackVideoDatesCallback)callback;

/**
 * @brief 搜索设备指定日期包含的回放事件
 * @param date 搜索回放录像的日期
 * @param startIndex 录像事件开始索引
 * @param endIndex 录像事件结束索引
 * @param callback 结果回调， 参数：1. 客户端ID；2. 回放事件数组，代表请求得到的所有回放事件；3. 请求错误信息
 * @discussion endIndex与startIndex之差最大为99，即调用一次该请求，最多能获取100个事件
 *
 */
- (void)reqPlaybackVideoAt:(NSDate *)date
                startIndex:(NSInteger)startIndex
                  endIndex:(NSInteger)endIndex
                  callback:(SMBCloudSDKPlaybackVideoListCallback)callback;

/**
 * @brief 搜索设备指定日期包含的人形侦测录像数据
 * @param date 搜索回放录像的日期
 * @param callback 结果回调，参数：1. 客户端ID；2. 回放事件数组，代表请求得到的所有回放事件；3. 请求错误信息
 *
 */
- (void)reqPlaybackHumanDetectionVideoAt:(NSDate *)date
                                callback:(SMBCloudSDKPlaybackVideoListCallback)callback;

/**
 * @brief 获取设备支持的播放倍数
 * @param callback 结果回调，参数：1. 播放倍数数组，代表设备支持的播放倍数，若请求失败则返回空数组；2. 请求错误信息
 *
 */
- (void)reqPlaybackScaleInfoListWithCallback:(SMBCloudSDKPlaybackGetScaleInfoListCallback)callback;


@end

@interface SMBCloudSDKPlaybackManager (Player)

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
 * @brief 开始回放
 * @param playbackParams 回放参数
 * @param streamParam 音视频流参数
 * @param beginTime 开始时间
 * @param endTime 结束时间
 * @param numerator 回放倍速分子
 * @param denominator 回放倍速分母
 */
- (void)startPlaybackWithParams:(SMBCloudSDKPlaybackParams *)playbackParams
                    streamParam:(SMBCloudSDKPlayerStreamParam *)streamParam
                      beginTime:(NSDate *)beginTime
                        endTime:(NSDate *)endTime
                      numerator: (NSInteger)numerator
                    denominator:(NSInteger)denominator
NS_SWIFT_NAME(startPlayback(playbackParams:streamParam:beginTime:endTime:numerator:denominator:));

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
 * @brief 切换播放进度（仅回放可用）
 * @param time 播放时间
 */
- (BOOL)seekTime:(time_t)time
NS_SWIFT_NAME(seekTime(time:));
/**
 * @brief 设置音量
 * @param volume 音量
 */
- (void)setVolume:(NSInteger)volume
NS_SWIFT_NAME(setVolume(volume:));
/**
 * @brief 设置回放倍速，需传入分子和分母（仅回放可用）
 * @param speedNumerator 回放倍速分子
 * @param speedDenominator 回放倍速分母
 */
- (void)setSpeedNumerator:(NSInteger)speedNumerator speedDenominator:(NSInteger)speedDenominator
NS_SWIFT_NAME(setSpeed(speedNumerator:speedDenominator:));

/**
 * @brief 设置回放开始、结束时间
 * @param startTime 开始时间
 * @param endTime 结束时间
 */
- (void)setPlaybackStartTime:(NSTimeInterval)startTime endTime:(NSTimeInterval)endTime
NS_SWIFT_NAME(setPlayback(startTime:endTime:));
/**
 * @brief 更新回放事件类型
 * @param eventTypes 事件类型
 * @param isEventsExcluded 是否为不包含事件
 */
- (void)updateEventTypes:(NSArray<NSNumber *> *)eventTypes
        isEventsExcluded:(BOOL)isEventsExcluded
NS_SWIFT_NAME(updateEventTypes(eventTypes:isEventsExcluded:));
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
