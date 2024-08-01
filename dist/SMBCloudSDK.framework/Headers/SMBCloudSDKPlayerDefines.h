//
//  SMBCloudSDKPlayerDefines.h
//  Pods
//
//  Created by Li Weijian on 2023/9/23.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
* @brief 播放器状态 相关
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKPlayerStatus) {
    /** @brief 播放器状态: 非法状态 */
    SMBCloudSDKPlayerStatusInvalid = 0,
    /** @brief 播放器状态: 加载中 */
    SMBCloudSDKPlayerStatusLoading,
    /** @brief 播放器状态: 播放中 */
    SMBCloudSDKPlayerStatusPlaying,
    /** @brief 播放器状态: 已暂停 */
    SMBCloudSDKPlayerStatusPaused,
    /** @brief 播放器状态: 拉流失败 */
    SMBCloudSDKPlayerStatusNoStream,
    /** @brief 播放器状态: 播放失败 */
    SMBCloudSDKPlayerStatusFailure,
    /** @brief 播放器状态: 已停止 */
    SMBCloudSDKPlayerStatusStopped,
};

/**
* @brief 播放器停止原因 相关
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKPlayerFinishReason) {
    /** @brief 播放器停止原因: 无 */
    SMBCloudSDKPlayerFinishReasonNone = -1,
    /** @brief 播放器停止原因: 超时断开连接 */
    SMBCloudSDKPlayerFinishReasonTimeOut = 0,
    /** @brief 播放器停止原因: 旧设备、新设备密码被其他终端修改 */
    SMBCloudSDKPlayerFinishReasonAuthFail = 1,
    /** @brief 播放器停止原因: 加载失败，点击重试 */
    SMBCloudSDKPlayerFinishReasonError = 2,
    /** @brief 播放器停止原因: 设备内部错误 */
    SMBCloudSDKPlayerFinishReasonDeviceInterError = 3,
    /** @brief 播放器停止原因: 不支持的格式 */
    SMBCloudSDKPlayerFinishReasonUnsupportFormat = 4,
    /** @brief 播放器停止原因: 当前观看人数过多，请切换清晰度试试 */
    SMBCloudSDKPlayerFinishReasonTooManyRequests = 5,
    /** @brief 播放器停止原因: 服务不可达，断开连接 */
    SMBCloudSDKPlayerFinishReasonServiceUnavailable = 6,
    /** @brief 播放器停止原因: 暂停 */
    SMBCloudSDKPlayerFinishReasonPause = 7,
    /** @brief 播放器停止原因: 当前观看人数过多，请稍后重试 */
    SMBCloudSDKPlayerFinishReasonTooManyClient = 8,
    /** @brief 播放器停止原因: 带宽不足 */
    SMBCloudSDKPlayerFinishReasonInsufficientBandwidth = 9,
    /** @brief 播放器停止原因: 存储错误 */
    SMBCloudSDKPlayerFinishReasonStorageErrors = 10,
    /** @brief 播放器停止原因: 非分享时段内，无法观看 */
    SMBCloudSDKPlayerFinishReasonRangeExceeded = 11,
    /** @brief 播放器停止原因: 正常 */
    SMBCloudSDKPlayerFinishReasonNormal = 12,
    /** @brief 播放器停止原因: 没有本地存储，无法回放 */
    SMBCloudSDKPlayerFinishReasonSearchVideoStorageError = 13,
    /** @brief 播放器停止原因: 设备不在线 */
    SMBCloudSDKPlayerFinishReasonDeviceOffline = 14,
    /** @brief 播放器停止原因: 设备已解绑 */
    SMBCloudSDKPlayerFinishReasonDeviceUnbind = 15,
    /** @brief 播放器停止原因: 当前网络不可用，请检查网络设置后重试 */
    SMBCloudSDKPlayerFinishReasonNoInternetConnection = 16,
    /** @brief 播放器停止原因: 需要用户授权允许流量播放 */
    SMBCloudSDKPlayerFinishReasonNotAllowCelluar = 17,
    /** @brief 播放器停止原因: 流量已达到限额，需要授权 */
    SMBCloudSDKPlayerFinishReasonCellularUsageRemind = 18,
    /** @brief 播放器停止原因: 超过允许的时间限制，断开连接 */
    SMBCloudSDKPlayerFinishReasonOverTimeLimit = 19,
    /** @brief 播放器停止原因: 设备被锁定 */
    SMBCloudSDKPlayerFinishReasonSyslocked = 20,
    /** @brief 播放器停止原因: 该通道未添加设备 */
    SMBCloudSDKPlayerFinishReasonInvalidChannel = 21,
    /** @brief 播放器停止原因: NVR不支持此编码方式，请切换清晰度或者修改编码方式后重试 */
    SMBCloudSDKPlayerFinishReasonUnsupportVideoCodecType = 22,
    /** @brief 播放器停止原因: 参数错误 */
    SMBCloudSDKPlayerFinishReasonParameterError = 23,
    /** @brief 播放器停止原因: 请求太频繁，请稍后重试 */
    SMBCloudSDKPlayerFinishReasonFrequentRequest = 24,
    /** @brief 播放器停止原因: 服务器繁忙，请稍后重试 */
    SMBCloudSDKPlayerFinishReasonServerInternalError = 25,
    /** @brief 播放器停止原因: 请绑定后重试 */
    SMBCloudSDKPlayerFinishReasonServerPermissionDenied = 26,
    /** @brief 播放器停止原因: 网络异常，请稍后重试 */
    SMBCloudSDKPlayerFinishReasonRequestTimeout = 27,
    /** @brief 播放器停止原因: 该设备已被其他用户绑定 */
    SMBCloudSDKPlayerFinishReasonDevicePermissionDenied = 28,
    /** @brief 播放器停止原因: 登录过期，请重新登录后重试 */
    SMBCloudSDKPlayerFinishReasonTokenExpired = 29,
    /** @brief 播放器停止原因: 该设备不存在 */
    SMBCloudSDKPlayerFinishReasonDeviceIdNotExist = 30,
    /** @brief 播放器停止原因: 分享不存在 */
    SMBCloudSDKPlayerFinishReasonShareExpired = 31,
    /** @brief 播放器停止原因: 设备连接异常，请稍后重试 */
    SMBCloudSDKPlayerFinishReasonDeivceException = 32,
    /** @brief 播放器停止原因: 连接数过多，请稍后重试 */
    SMBCloudSDKPlayerFinishReasonSessionUnavailable = 33,
    /** @brief 播放器停止原因: 文件id已满，无法分配 */
    SMBCloudSDKPlayerFinishReasonGreeterFileIdFull = 34,
    /** @brief 播放器停止原因: 密码错误，鉴权失败 */
    SMBCloudSDKPlayerFinishReasonAuthentication = 35,
    /** @brief 播放器停止原因: 索引请求参数错误 */
    SMBCloudSDKPlayerFinishReasonCsIndexReq = 36,
    /** @brief 播放器停止原因: 索引响应超时或错误 */
    SMBCloudSDKPlayerFinishReasonCsIndexResp = 37,
    /** @brief 播放器停止原因: 密钥请求参数错误 */
    SMBCloudSDKPlayerFinishReasonCsDecryptReq = 38,
    /** @brief 播放器停止原因: 密钥响应超时或错误 */
    SMBCloudSDKPlayerFinishReasonCsDecryptResp = 39,
    /** @brief 播放器停止原因: 网络初始化错误 */
    SMBCloudSDKPlayerFinishReasonCsSegInitErr = 40,
    /** @brief 播放器停止原因: 未知录像媒体类型 */
    SMBCloudSDKPlayerFinishReasonCsSegMediaErr = 41,
    /** @brief 播放器停止原因: 当天录像已播完 */
    SMBCloudSDKPlayerFinishReasonCsNoStream = 42,
    /** @brief 播放器停止原因: 不支持的解密方式 */
    SMBCloudSDKPlayerFinishReasonCsDecryptNotSupport = 43,
    /** @brief 播放器停止原因: 数据被重定向 */
    SMBCloudSDKPlayerFinishReasonCsSeg3xx = 44,
    /** @brief 播放器停止原因: 服务器异常403，请重试 */
    SMBCloudSDKPlayerFinishReasonCsSeg403 = 45,
    /** @brief 播放器停止原因: 录像文件不存在 */
    SMBCloudSDKPlayerFinishReasonCsSeg404 = 46,
    /** @brief 播放器停止原因: 客户端错误 */
    SMBCloudSDKPlayerFinishReasonCsSeg4xx = 47,
    /** @brief 播放器停止原因: 客户端异常 */
    SMBCloudSDKPlayerFinishReasonCsSeg503 = 48,
    /** @brief 播放器停止原因: 服务器异常 */
    SMBCloudSDKPlayerFinishReasonCsSeg5xx = 49,
    /** @brief 播放器停止原因: 音视频数据解密错误 */
    SMBCloudSDKPlayerFinishReasonDecryptError = 50,
    /** @brief 播放器停止原因: 分享已失效 */
    SMBCloudSDKPlayerFinishReasonShareDisabled = 51,
    /** @brief 播放器停止原因: 当前软件版本过低，请升级后使用 */
    SMBCloudSDKPlayerFinishReasonLowVersion = 52,
    /** @brief 播放器停止原因: 文件大小有误 */
    SMBCloudSDKPlayerFinishReasonWrongFileSize = 53,
    /** @brief 播放器停止原因: 没有本地存储，无法回放 */
    SMBCloudSDKPlayerFinishReasonNoStorageMedia = 54,
    /** @brief 播放器停止原因: VIP窗口预览数达到上限 */
    SMBCloudSDKPlayerFinishReasonTooManyVipWindows = 55,
    /** @brief 播放器停止原因: VIP预览客户端数量达到上限  */
    SMBCloudSDKPlayerFinishReasonTooManyVipClients = 56,
    /** @brief 播放器停止原因: 达到播放时长限制 */
    SMBCloudSDKPlayerFinishReasonRelayLifetimeExpired = 57,
    /** @brief 播放器停止原因: NVR通道设备正在通话中 */
    SMBCloudSDKPlayerFinishReasonChannelTalkBusy = 58,
    /** @brief 播放器停止原因: 播放异常 */
    SMBCloudSDKPlayerFinishReasonStreamException = 59,
    /** @brief 播放器停止原因: 观看人数达到上限 */
    SMBCloudSDKPlayerFinishReasonPreviewNumLimited = 60,
    /** @brief 播放器停止原因: 正在播放时不允许搜索事件 */
    SMBCloudSDKPlayerFinishReasonForbidSearcEventhWhenPlaying = 61,
    /** @brief 播放器停止原因: 暂停时连接出错 */
    SMBCloudSDKPlayerFinishReasonErrorWhenPause = 62,
    /** @brief 播放器停止原因: 视频流获取失败 */
    SMBCloudSDKPlayerFinishReasonGetUrlFail = 63,
    /** @brief 播放器停止原因: 无录像 */
    SMBCloudSDKPlayerFinishReasonNoStream = 64,
    /** @brief 播放器停止原因: 服务器离线 */
    SMBCloudSDKPlayerFinishReasonServiceOffline = 65,
    /** @brief 播放器停止原因: 未发现存储设备 */
    SMBCloudSDKPlayerFinishReasonNotFoundStorage = 66,
    /** @brief 播放器停止原因: 设备未绑定到流媒体服务器 */
    SMBCloudSDKPlayerFinishReasonDeviceUnbindMediaServer = 67,
    /** @brief 播放器停止原因: 权限不足 */
    SMBCloudSDKPlayerFinishReasonPermissionDeny = 68,
    /** @brief 播放器停止原因: 回放暂不支持直连接入的IPC */
    SMBCloudSDKPlayerFinishReasonPlaybackNotSupportIPC = 69,
    /** @brief 播放器停止原因: 服务器未授权 */
    SMBCloudSDKPlayerFinishReasonServiceUnauthorized = 70,
    /** @brief 播放器停止原因: 无预览权限 */
    SMBCloudSDKPlayerFinishReasonNoPreviewPermission = 71,
    /** @brief 播放器停止原因: 音频设备忙，无法发起对讲 */
    SMBCloudSDKPlayerFinishReasonDeviceVoiceBusy = 72,
    /** @brief 播放器停止原因: 设备不支持该操作 */
    SMBCloudSDKPlayerFinishReasonDeviceUnsupportOperation = 73,
    /** @brief 播放器停止原因: 设备接入服务器离线 */
    SMBCloudSDKPlayerFinishReasonAddDeviceServiceOffline = 74,
    /** @brief 播放器停止原因: 余额不足 */
    SMBCloudSDKPlayerFinishReasonInsufficientBalance = 75,
    /** @brief 播放器停止原因: 数据流超过最大持续时间 */
    SMBCloudSDKPlayerFinishReasonTimeExpired = 76,
    /** @brief 播放器停止原因: 设备休眠中 */
    SMBCloudSDKPlayerFinishReasonLowPowerDormant = 77,
    /** @brief 播放器停止原因: 低功耗唤醒中 */
    SMBCloudSDKPlayerFinishReasonLowPowerWakingUp = 78,
     /** @brief 播放器停止原因: 配置不存在 */
    SMBCloudSDKPlayerFinishReasonConfigurationNotExist = 79
};


/**
* @brief 截图结束原因 相关
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKPlayerSnapshotFinishReason) {
    /** 截图结束原因: 通用错误 */
    SMBCloudSDKPlayerSnapshotFinishReasonGeneral = -1,
    /** 截图结束原因: 正常 */
    SMBCloudSDKPlayerSnapshotFinishReasonOK = 0,
    /** 截图结束原因: 存储已满 */
    SMBCloudSDKPlayerSnapshotFinishReasonFullDisk = 1
};

/**
* @brief 截图类型 相关
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKPlayerSnapshotType) {
    /** @brief 截图类型: 普通播放截图 */
    SMBCloudSDKPlayerSnapshotTypeDefault = 0,
    /** @brief 截图类型: 截最后一帧 */
    SMBCloudSDKPlayerSnapshotTypeLastFrame,
    /** @brief 截图类型: 截第一帧 */
    SMBCloudSDKPlayerSnapshotTypeFistFrame,
    /** @brief 截图类型: 连续截图 */
    SMBCloudSDKPlayerSnapshotTypeMulti,

    /** @brief 截图类型: 预置点截图 */
    SMBCloudSDKPlayerSnapshotTypePreset,
    /** @brief 截图类型: 封面截图 */
    SMBCloudSDKPlayerSnapshotTypeCover,
    /** @brief 截图类型: 热力图截图 */
    SMBCloudSDKPlayerSnapshotTypeHeatMap,
    /** @brief 截图类型: 设置截图 */
    SMBCloudSDKPlayerSnapshotTypeSetting,
    /** @brief 截图类型: 鱼眼预置点截图 */
    SMBCloudSDKPlayerSnapshotTypeFisheyePreset,
};


/**
* @brief 录制结束原因 相关
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKPlayerRecordFinishReason) {
    /** @brief 录制结束原因: 通用错误 */
    SMBCloudSDKPlayerRecordFinishReasonGeneral = -1,
    /** @brief 录制结束原因: 正常 */
    SMBCloudSDKPlayerRecordFinishReasonOK = 0,
    /** @brief 录制结束原因: 录像太短 */
    SMBCloudSDKPlayerRecordFinishReasonVideoTooShort = 1,
    /** @brief 录制结束原因: 手机存储空间不足，无法开始录像 */
    SMBCloudSDKPlayerRecordFinishReasonFullDisk = 2,
    /** @brief 录制结束原因: 手机存储空间不足，无法继续录制，已录片段已自动保存 */
    SMBCloudSDKPlayerRecordFinishReasonEndWithFullDisk = 3,
    /** @brief 录制结束原因: 不支持的格式 */
    SMBCloudSDKPlayerRecordFinishReasonUnsupportFormat = 4,
    /** @brief 录制结束原因: 输入/输出错误 */
    SMBCloudSDKPlayerRecordFinishReasonIOError = 5
};

/**
* @brief 清晰度 相关
*/
typedef NS_ENUM(NSInteger, SMBCloudSDKPlayerResolution) {
    /** @brief 清晰度: 无 */
    SMBCloudSDKPlayerResolutionNone = -1,
    /** @brief 清晰度: 流畅 */
    SMBCloudSDKPlayerResolutionVGA = 0,
    /** @brief 清晰度: 高清 */
    SMBCloudSDKPlayerResolutionHD = 1,
    /** @brief 清晰度: 第三码流（超高清） */
    SMBCloudSDKPlayerResolutionTHIRD = 2
};

/**
* @brief 播放器解码模式
*/
typedef NS_ENUM(NSUInteger, SMBCloudSDKPlayerDecodeMode) {
    /** @brief 播放器解码模式: 优先选用硬解 */
    SMBCloudSDKPlayerDecodeModeHardwareFirst = 0,
    /** @brief 播放器解码模式: 选用软解 */
    SMBCloudSDKPlayerDecodeModeSoftwareOnly
};

/**
 * @brief 播放器对讲模式
 */
typedef NS_ENUM(NSUInteger, SMBCloudSDKPlayerSpeechMode) {
    /** @brief 播放器对讲模式: 对讲模式 */
    SMBCloudSDKPlayerSpeechModeSpeak = 0,
    /** @brief 播放器对讲模式: 电话模式 */
    SMBCloudSDKPlayerSpeechModeCall,
};

/**
 * @brief 播放器画面拉伸模式
 */
typedef NS_ENUM(NSUInteger, SMBCloudSDKPlayerScaleMode) {
    /** @brief 播放器画面拉伸模式: 拉伸填充 */
    SMBCloudSDKPlayerScaleModeFill = 0,
    /** @brief 播放器画面拉伸模式: 保持画面比例 */
    SMBCloudSDKPlayerScaleModeAspectFit,
    /** @brief 播放器画面拉伸模式: 铺满屏幕，当画面和屏幕的宽高比例不相等时，画面会有部分被裁剪掉，显示不全 */
    SMBCloudSDKPlayerScaleModeFillCrap,
};

/**
 *  @brief 鱼眼设备支持的视频显示模式
 */
typedef NSString *SMBCloudSDKFishEyeDisplayMode NS_STRING_ENUM;
/** @brief 视频显示模式：原始模式，对于鱼眼设备理论上不会出现 **/
FOUNDATION_EXPORT SMBCloudSDKFishEyeDisplayMode const SMBCloudSDKFishEyeDisplayModeOrigin;
/** @brief 视频显示模式：顶装360 度全景模式 **/
FOUNDATION_EXPORT SMBCloudSDKFishEyeDisplayMode const SMBCloudSDKFishEyeDisplayModeTop360D;
/** @brief 视频显示模式：顶装180 度全景模式 **/
FOUNDATION_EXPORT SMBCloudSDKFishEyeDisplayMode const SMBCloudSDKFishEyeDisplayModeTop180D;
/** @brief 视频显示模式：顶装圆柱体模式 **/
FOUNDATION_EXPORT SMBCloudSDKFishEyeDisplayMode const SMBCloudSDKFishEyeDisplayModeTopCylinder;
/** @brief 视频显示模式：顶装四分屏模式 **/
FOUNDATION_EXPORT SMBCloudSDKFishEyeDisplayMode const SMBCloudSDKFishEyeDisplayModeWinPlaneTopQuad;
/** @brief 视频显示模式：顶装原图模式 ( 半球形贴图 ) **/
FOUNDATION_EXPORT SMBCloudSDKFishEyeDisplayMode const SMBCloudSDKFishEyeDisplayModeWinPlaneTop;
/** @brief 视频显示模式：壁装水平展开模式 **/
FOUNDATION_EXPORT SMBCloudSDKFishEyeDisplayMode const SMBCloudSDKFishEyeDisplayModeWallLongitude;
/** @brief 视频显示模式：壁装全景拉伸模式 **/
FOUNDATION_EXPORT SMBCloudSDKFishEyeDisplayMode const SMBCloudSDKFishEyeDisplayModeWallCalib;
/** @brief 视频显示模式：壁装原图模式（半球形贴图）**/
FOUNDATION_EXPORT SMBCloudSDKFishEyeDisplayMode const SMBCloudSDKFishEyeDisplayModeWinPlaneWall;
/** @brief 视频显示模式：壁装竖直全景拉伸模式 **/
FOUNDATION_EXPORT SMBCloudSDKFishEyeDisplayMode const SMBCloudSDKFishEyeDisplayModeWallLatitude;
NS_ASSUME_NONNULL_END
