//
//  SMBCloudSDKDeviceSettingManager.h
//  Pods
//
//  Created by chenkairong on 2024/2/21.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKError.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceFailInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceSDInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDCapability.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDInfoParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDEnum.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDWatermarkInfo.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^SMBCloudSDKDeviceSettingCommonCompletion)(__kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKDeviceSettingBatchOperationCompletion)(__kindof SMBCloudSDKError * error, NSArray<SMBCloudSDKDeviceFailInfo *> *failList);
typedef void (^SMBCloudSDKDeviceSettingGetSDInfoCompletion)(__kindof SMBCloudSDKError * error, NSArray<SMBCloudSDKDeviceSDInfo *> *infoList);
typedef void (^SMBCloudSDKDeviceSettingGetRecordLoopInfoCompletion)(__kindof SMBCloudSDKError * error, BOOL isLoopOn);
typedef void (^SMBCloudSDKDeviceSettingContextGetOSDCapabilityCompletion)(SMBCloudSDKDeviceOSDCapability * _Nullable osdCapacity, __kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKDeviceSettingContextGetOSDInfoCompletion)(SMBCloudSDKDeviceOSDInfo * _Nullable osdInfo, __kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKDeviceSettingContextGetOSDFontDisplayCompletion)(BOOL ifBlink, __kindof SMBCloudSDKError * error);

@interface SMBCloudSDKDeviceSettingManager: NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)shared NS_SWIFT_NAME(shared());

/**
 * @brief 删除设备
 * @discussion 仅支持删除NVR和直连IPC
 *
 * @param deviceParamList  设备参数数组
 * @see SMBCloudSDKDeviceParam
 * @param onlyRemove 是否仅从设备型应用（需要在商云开发者-应用管理页面对应用中的设备进行管理）中移除，false表示不仅从设备型应用中移除，且从商云解绑
 * @param completion 请求结果回调
 */
- (void)requestDeleteDevicesWithDeviceParamList:(NSArray<SMBCloudSDKDeviceParam *> *)deviceParamList
                                     onlyRemove:(BOOL)onlyRemove
                                     completion:(SMBCloudSDKDeviceSettingBatchOperationCompletion)completion
NS_SWIFT_NAME(requestDeleteDevices(deviceParamList:onlyRemove:completion:));

/**
 * @brief 重启设备
 *
 * @param deviceParamList  设备参数数组
 * @see SMBCloudSDKDeviceParam
 * @param completion 请求结果回调
 */
- (void)requestRebootDevicesWithDeviceParamList:(NSArray<SMBCloudSDKDeviceParam *> *)deviceParamList
                                     completion:(SMBCloudSDKDeviceSettingBatchOperationCompletion)completion
NS_SWIFT_NAME(requestRebootDevices(deviceParamList:completion:));

/**
 * @brief 修改设备名称
 *
 * @param device  设备对象（可传空，若传入会更新设备对象的名称）
 * @param deviceParam 设备参数
 * @see SMBCloudSDKDeviceParam
 * @param name 设置的新名称（设备名称长度限制1-32个字符，1个中文算3个字符，若超过长度限制会报参数错误。）
 * @param completion 请求结果回调
 */
- (void)requestModifyDeviceNameWithDevice:(nullable SMBCloudSDKDevice *)device
                              deviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                                     name:(NSString *)name
                               completion:(SMBCloudSDKDeviceSettingCommonCompletion)completion
NS_SWIFT_NAME(requestModifyDeviceName(device:deviceParam:name:completion:));

/**
 * @brief 获取sd卡信息
 *
 * @param deviceParam  设备参数
 * @see SMBCloudSDKDeviceParam
 * @param completion 请求结果回调
 */
- (void)requestGetSDInfoWithDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                             completion:(SMBCloudSDKDeviceSettingGetSDInfoCompletion)completion
NS_SWIFT_NAME(requestGetSDInfo(deviceParam:completion:));

/**
 * @brief 格式化sd卡（请求成功后需通过获取sd卡信息拿到对应状态判断格式化是否完成）
 *
 * @param deviceParam  设备参数
 * @see SMBCloudSDKDeviceParam
 * @param cardIndex  sd卡索引值
 * @param completion 请求结果回调
 */
- (void)requestFormatSDCardWithDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                                 cardIndex:(NSInteger)cardIndex
                                completion:(SMBCloudSDKDeviceSettingCommonCompletion)completion
NS_SWIFT_NAME(requestFormatSDCard(deviceParam:cardIndex:completion:));

/**
 * @brief 获取录像循环开关状态
 *
 * @param deviceParam  设备参数
 * @see SMBCloudSDKDeviceParam
 * @param completion 请求结果回调
 */
- (void)requestGetRecordLoopInfoWithDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                                     completion:(SMBCloudSDKDeviceSettingGetRecordLoopInfoCompletion)completion
NS_SWIFT_NAME(requestGetRecordLoopInfo(deviceParam:completion:));

/**
 * @brief 设置录像循环开关状态
 *
 * @param deviceParam  设备参数
 * @see SMBCloudSDKDeviceParam
 * @param enable  是否开启录像循环
 * @param completion 请求结果回调
 */
- (void)requestSetRecordLoopInfoWithDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                                         enable:(BOOL)enable
                                     completion:(SMBCloudSDKDeviceSettingCommonCompletion)completion
NS_SWIFT_NAME(requestSetRecordLoopInfo(deviceParam:enable:completion:));

/**
 * @brief 获取IPC设备OSD能力集
 *
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param deviceParam 设备参数
 * @param completion 请求结束后回调，参数：1.获取到的OSD能力集对象 2.请求错误信息
 * @see SMBCloudSDKDeviceParam
 */
- (void)requestGetDeviceOSDCapability:(SMBCloudSDKDeviceParam *)deviceParam
                           completion:(SMBCloudSDKDeviceSettingContextGetOSDCapabilityCompletion)completion
NS_SWIFT_NAME(requestGetDeviceOSDCapability(deviceParam:completion:));

/**
 * @brief 获取IPC设备日期、星期、字体、自定义字符串的 OSD 信息
 *
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param deviceParam 设备参数
 * @param completion 请求结束后回调，参数：1.获取到的设备日期、星期、字体、自定义字符串的 OSD 信息 2.请求错误信息
 * @see SMBCloudSDKDeviceParam
 */
- (void)requestGetDeviceOSDInfo:(SMBCloudSDKDeviceParam *)deviceParam
                     completion:(SMBCloudSDKDeviceSettingContextGetOSDInfoCompletion)completion
NS_SWIFT_NAME(requestGetDeviceOSDInfo(deviceParam:completion:));

/**
 * @brief 修改IPC 设备日期、星期、字体、自定义字符串的 OSD 信息
 *
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param osdInfo IPC 设备日期、星期、字体、自定义字符串的 OSD 信息对象（可传空，若传入会更新OSD信息对象的名称）
 * @param osdInfoParam 设置IPC 设备日期、星期、字体、自定义字符串的新 OSD 信息对象
 * @param deviceParam 设备参数
 * @param completion 请求结束后回调，参数：1.请求错误信息
 * @see SMBCloudSDKDeviceOSDInfo
 * @see SMBCloudSDKDeviceOSDInfoParam
 * @see SMBCloudSDKDeviceParam
 */
- (void)requestModifyDeviceOSDInfo:(nullable SMBCloudSDKDeviceOSDInfo *)osdInfo
                  withOSDInfoParam:(SMBCloudSDKDeviceOSDInfoParam *)osdInfoParam
                   withDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                        completion:(SMBCloudSDKDeviceSettingCommonCompletion)completion
NS_SWIFT_NAME(requestModifyDeviceOSDInfo(osdInfo:osdInfoParam:deviceParam:completion:));

/**
 * @brief 获取OSD字体闪烁配置
 *
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param deviceParam 设备参数
 * @param completion 请求结束后回调，参数：1.请求错误信息
 * @see SMBCloudSDKDeviceParam
 */
- (void)requestGetDeviceOSDFontDisplay:(SMBCloudSDKDeviceParam *)deviceParam
                            completion:(SMBCloudSDKDeviceSettingContextGetOSDFontDisplayCompletion)completion
NS_SWIFT_NAME(requestGetDeviceOSDFontDisplay(deviceParam:completion:));

/**
 * @brief 配置OSD字体是否闪烁
 *
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param ifBlink 是否闪烁
 * @param deviceParam 设备参数
 * @param completion 请求结束后回调，参数：1.请求错误信息
 * @see SMBCloudSDKDeviceParam
 */
- (void)requestModifyDeviceOSDFontDisplay:(BOOL)ifBlink
                          withDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                               completion:(SMBCloudSDKDeviceSettingCommonCompletion)completion
NS_SWIFT_NAME(requestModifyDeviceOSDFontDisplay(ifBlink:deviceParam:completion:));

/**
 * @brief 修改IPC设备OSD数字水印基本信息
 *
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param watermarkBasicInfo OSD数字水印基本信息
 * @param deviceParam 设备参数
 * @param completion 请求结束后回调，参数：1.请求错误信息
 * @see SMBCloudSDKDeviceOSDWatermarkBasicInfo
 * @see SMBCloudSDKDeviceParam
 */
- (void)requestModifyDeviceOSDWatermarkBasicInfo:(SMBCloudSDKDeviceOSDWatermarkBasicInfo *)watermarkBasicInfo
                                 withDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                                      completion:(SMBCloudSDKDeviceSettingCommonCompletion)completion
NS_SWIFT_NAME(requestModifyDeviceOSDWatermarkBasicInfo(watermarkBasicInfo:deviceParam:completion:));

/**
 * @brief 修改IPC设备OSD数字水印动态字符串信息
 *
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param dynamicLabelInfo OSD数字水印动态字符串信息
 * @param deviceParam 设备参数
 * @param completion 请求结束后回调，参数：1.请求错误信息
 * @see SMBCloudSDKDeviceOSDWatermarkDynamicLabelInfo
 * @see SMBCloudSDKDeviceParam
 */
- (void)requestAddDeviceOSDWatermarkDynamicLabelInfo:(SMBCloudSDKDeviceOSDWatermarkDynamicLabelInfo *)dynamicLabelInfo
                                     withDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                                          completion:(SMBCloudSDKDeviceSettingCommonCompletion)completion
NS_SWIFT_NAME(requestAddDeviceOSDWatermarkDynamicLabelInfo(dynamicLabelInfo:deviceParam:completion:));

/**
 * @brief 修改IPC设备OSD数字水印静态字符串信息
 *
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param solidLabelInfo OSD数字水印静态字符串信息
 * @param deviceParam 设备参数
 * @param completion 请求结束后回调，参数：1.请求错误信息
 * @see SMBCloudSDKDeviceOSDWatermarkSolidLabelInfo
 * @see SMBCloudSDKDeviceParam
 */
- (void)requestModifyDeviceOSDWatermarkSolidLabelInfo:(SMBCloudSDKDeviceOSDWatermarkSolidLabelInfo *)solidLabelInfo
                                      withDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                                           completion:(SMBCloudSDKDeviceSettingCommonCompletion)completion
NS_SWIFT_NAME(requestModifyDeviceOSDWatermarkSolidLabelInfo(solidLabelInfo:deviceParam:completion:));

/**
 * @brief 清空IPC设备OSD数字水印信息
 *
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param type 清除内容的方式
 * @param deviceParam 设备参数
 * @param completion 请求结束后回调，参数：1.请求错误信息
 * @see SMBCloudSDKDeviceOSDCleanType
 * @see SMBCloudSDKDeviceParam
 */
- (void)requestClearDeviceOSDWatermarkInfo:(SMBCloudSDKDeviceOSDCleanType)type
                           withDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                                completion:(SMBCloudSDKDeviceSettingCommonCompletion)completion
NS_SWIFT_NAME(requestClearDeviceOSDWatermarkInfo(type:deviceParam:completion:));

/**
 * @brief 解绑NVR通道。
 * @discussion 将使用设备透传命令解绑通道，成功后想要再次绑定需去现场访问设备web。 使用限制：NVR需要处于在线状态。错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param nvrParam NVR设备参数
 * @see SMBCloudSDKDeviceParam
 * @param channelId 通道Id，从1开始。
 * @param completion 请求结束后回调，参数：请求错误信息
 */
- (void)requestUnbindNVRChannelByNVRParam:(SMBCloudSDKDeviceParam *)nvrParam
                              channleId:(NSInteger)channelId
                             completion:(SMBCloudSDKDeviceSettingCommonCompletion)completion
NS_SWIFT_NAME(requestUnbindNVRChannel(deviceParam:channelId:completion:));

@end

NS_ASSUME_NONNULL_END
