//
//  SMBCloudSDKDeviceAddManager.h
//  Pods
//
//  Created by chenkairong on 2023/9/22.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKError.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceForScanList.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceAddEnumDefines.h>
#import <SMBCloudSDK/SMBCloudSDKOnboardWiFiInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceBindStatusInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceFailInfo.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceAddNVRChannelInfo.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^SMBCloudSDKDeviceAddManagerCommonCompletion)(__kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKDeviceAddManagerScanWIFICompletion)(__kindof SMBCloudSDKError * error, NSArray<SMBCloudSDKOnboardWiFiInfo *> *wifiInfoList);
typedef void (^SMBCloudSDKDeviceAddManagerSendWIFIInfoCompletion)(__kindof SMBCloudSDKError * error, BOOL isSupportAp, NSString * devMac);
typedef void (^SMBCloudSDKDeviceAddManagerConnectStatusCompletion)(__kindof SMBCloudSDKError * error, SMBCloudSDKOnboardConnectStatus status);
typedef void (^SMBCloudSDKDeviceAddManagerScanDeviceCompletion)(__kindof SMBCloudSDKError * error, SMBCloudSDKDeviceForScanList  * _Nullable scannedDevice);
typedef void (^SMBCloudSDKDeviceAddManagerDiscoverByDeviceTypeCompletion)(__kindof SMBCloudSDKError * error, NSArray<SMBCloudSDKDeviceForScanList *> *scanList);
typedef void (^SMBCloudSDKDeviceAddManagerRequestDevicesBindStatusCompletion)(__kindof SMBCloudSDKError * error, NSArray<SMBCloudSDKDeviceBindStatusInfo *> *bindInfoList);
typedef void (^SMBCloudSDKDeviceAddManagerMoveDeviceListToRegionCompletion)(__kindof SMBCloudSDKError * error, NSArray<SMBCloudSDKDeviceFailInfo *> *failList);
typedef void (^SMBCloudSDKDeviceAddManagerGetNotAddedIPCListCompltion)(__kindof SMBCloudSDKError * error, BOOL finished, NSArray<SMBCloudSDKNotAddedIPCInfo *> *ipcList);
typedef void (^SMBCloudSDKDeviceAddManagerAddIPCListToNVRCompletion)(__kindof SMBCloudSDKError * error, NSArray<SMBCloudSDKAddChannelIPCResult *> *failedList);

@interface SMBCloudSDKDeviceAddManager: NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)shared NS_SWIFT_NAME(shared()); // 提供单例给其他模块

/**
 * @brief 请求SmartConfig配网，会一直配网，需要调用stopSmartConfigDevice手动停止
 *
 * @param qrCode        设备二维码
 * @param ssid          WiFi名称
 * @param password      WiFi密码
 *
 */
- (void)requestSmartConfigDeviceWithQRCode:(NSString *)qrCode
                                      ssid:(NSString *)ssid
                                  password:(NSString *)password
NS_SWIFT_NAME(requestSmartConfigDevice(qrCode:ssid:password:));

/**
 * @brief 停止SmartConfig配网
 */
- (void)stopSmartConfigDevice;

/**
 * @brief 播放声波，会一直循环播放，需调用stopPlayAudioConfig手动停止
 *
 * @param ssid                WiFi名称
 * @param password          WiFi密码
 * @param version            声波版本
 * @param qrCode           设备二维码
 *
 * @return SMBCloudSDKAudioConfigInfo 声波内容
 */
- (void)playAudioConfigWithSSID:(NSString *)ssid
                       password:(NSString *)password
                        version:(SMBCloudSDKAudioVersionType)version
                         qrCode:(NSString *)qrCode
NS_SWIFT_NAME(playAudioConfig(ssid:password:version:qrCode:));

/**
 * @brief 停止播放声波
 *
 */
- (void)stopPlayAudioConfig;

/**
 * @brief SoftAP流程获取设备可配网的WIFI列表
 *
 * @param ip          设备IP
 * @param port          设备端口
 * @param completion     请求结果回调（SMBCloudSDKError，设备可配网WiFi信息集合）
 *
 */
- (void)requestScanWiFiWithIP:(NSString *)ip
                         port:(NSInteger)port
                   completion:(SMBCloudSDKDeviceAddManagerScanWIFICompletion)completion
NS_SWIFT_NAME(requestScanWiFi(ip:port:completion:));


/**
 * @brief SoftAP流程发送WiFi信息给设备
 *
 * @param ip         设备IP
 * @param port          设备端口
 * @param deviceType        设备类型
 * @param info        配网WiFi信息
 * @param completion    请求回调（SMBCloudSDKError，是否支持AP，设备mac地址（由long long转换而来））
 *
 */
- (void)requestSendWiFiInfoWithIP:(NSString *)ip
                             port:(NSInteger)port
                       deviceType:(SMBCloudSDKDeviceType)deviceType
                         wifiInfo:(SMBCloudSDKOnboardWiFiInfo *)info
                       completion:(SMBCloudSDKDeviceAddManagerSendWIFIInfoCompletion)completion
NS_SWIFT_NAME(requestSendWiFiInfo(ip:port:deviceType:info:completion:));


/**
 * @brief SoftAP流程查询设备配网连接状态（仅当requestSendWiFiInfoWithIP接口回调中的isSupportAp为true时才可调用）
 *
 * @param IP          设备IP
 * @param port          设备端口
 * @param completion        请求结果回调（SMBCloudSDKError，连接状态）
 *
 */
- (void)requestConnectStatusWithIP:(NSString *)ip
                              port:(NSInteger)port
                        completion:(SMBCloudSDKDeviceAddManagerConnectStatusCompletion)completion
NS_SWIFT_NAME(requestConnectStatus(ip:port:completion:));

/**
 * @brief 通过设备mac地址进行局域网发现设备
 *
 * @param mac               设备mac地址（传入mac为requestScanWiFiWithIP接口回调返回的mac）
 * @param completion       请求结果回调（SMBCloudSDKError，局域网发现的设备对象）
 *
 */
- (void)requestDiscoverDeviceWithMac:(NSString *)mac
                           completion:(SMBCloudSDKDeviceAddManagerScanDeviceCompletion)completion
NS_SWIFT_NAME(requestDiscoverDevice(mac:completion:));

/**
 * @brief 通过设备类型进行局域网发现设备
 *
 * @param deviceType        设备类型
 * @param completion       请求结果回调（SMBCloudSDKError，局域网发现的设备对象）
 *
 */
- (void)requestDiscoverDevicesWithDeviceType:(SMBCloudSDKDeviceType)deviceType
                                  completion:(SMBCloudSDKDeviceAddManagerDiscoverByDeviceTypeCompletion)completion
NS_SWIFT_NAME(requestDiscoverDevices(deviceType:completion:));

/**
* @brief  通过设备mac列表批量请求查询设备是否绑定
*
* @param macList          设备mac列表
* @param completion    设备状态回调（SMBSDKError，各个设备是否绑定）
*
*/
- (void)requestDevicesBindStatusWithMacList:(NSArray<NSString *> *)macList
                                completion:(SMBCloudSDKDeviceAddManagerRequestDevicesBindStatusCompletion)completion
NS_SWIFT_NAME(requestDevicesBindStatus(macList:completion:));

/**
 * @brief 通过qrCode添加设备
 *
 * @param qrCode                设备二维码
 * @param deviceUserName    设备用户名（用户名为web登陆设备的用户名）
 * @param devicePassword    设备密码，未设置过设备密码，此参数代表设置密码，设置过设备密码，此参数代表验证密码
 * @param completion       请求结果回调（SMBSDKError）
 *
 */
- (void)requestBindDeviceByQrCode:(NSString *)qrCode
                   deviceUserName:(NSString *)deviceUserName
                   devicePassword:(NSString *)devicePassword
                       completion:(SMBCloudSDKDeviceAddManagerCommonCompletion)completion
NS_SWIFT_NAME(requestBindDevice(qrCode:deviceUserName:devicePassword:completion:));

/**
 * @brief 通过局域网扫描到的设备类型添加设备
 *
 * @param scannedDevice      局域网扫描到的设备信息
 * @param deviceUserName    设备用户名（用户名为web登陆设备的用户名）
 * @param devicePassword    设备密码，未设置过设备密码，此参数代表设置密码，设置过设备密码，此参数代表验证密码
 * @param completion       请求结果回调（SMBSDKError）
 *
 */
- (void)requestBindDeviceByScannedDevice:(SMBCloudSDKDeviceForScanList *)scannedDevice
                          deviceUserName:(NSString *)deviceUserName
                          devicePassword:(NSString *)devicePassword
                              completion:(SMBCloudSDKDeviceAddManagerCommonCompletion)completion
NS_SWIFT_NAME(requestBindDevice(scannedDevice:deviceUserName:devicePassword:completion:));

/**
 * @brief 批量移动设备到对应分组
 *
 * @param regionId            分组id
 * @param deviceList       移动的设备信息
 * @param completion       请求结果回调（SMBSDKError，failList移动失败的设备信息及原因）
 *
 */
- (void)requestMoveDeviceListToRegionWithRegionId:(NSString *)regionId
                                       deviceList:(NSArray<SMBCloudSDKDeviceParam *>*)deviceList
                                       completion:(SMBCloudSDKDeviceAddManagerMoveDeviceListToRegionCompletion)completion
NS_SWIFT_NAME(requestMoveDeviceListToRegion(regionId:deviceList:completion:));

/**
 * @brief 控制NVR发现IPC设备
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误吗）
 * @param nvrParam NVR的设备参数
 * @see SMBCloudSDKDeviceParam
 * @param completion 请求结束后回调，参数：请求错误信息
 */
- (void)requestDiscoverIPCByNVRParam:(SMBCloudSDKDeviceParam *)nvrParam
                           completion:(SMBCloudSDKDeviceAddManagerCommonCompletion)completion
NS_SWIFT_NAME(requestDiscoverIPCByNVR(nvrParam:completion:));


/**
 * @brief 查询 NVR 发现同一局域网下未被添加的 IPC 进度
 * @discussion 需在调用发现设备接口(requestDiscoverIPCByNVR)后轮询调用该接口，直至回调的finish值为true。错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param nvrParam NVR的设备参数
 * @see SMBCloudSDKDeviceParam
 * @param completion 请求结束后回调，参数：1.请求错误信息 2.NVR发现设备的过程是否结束，该值为YES时，参数3的列表才有值 3.IPC列表
 */
- (void)requestGetNotAddedIPCListByNVRParam:(SMBCloudSDKDeviceParam *)nvrParam
                                  completion:(SMBCloudSDKDeviceAddManagerGetNotAddedIPCListCompltion)completion
NS_SWIFT_NAME(requestGetNotAddedIPCListByNVR(nvrParam:completion:));

/**
 * @brief 把IPC添加到NVR通道下
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param nvrParam NVR设备参数
 * @see SMBCloudSDKDeviceParam
 * @param activatePassword 激活密码。当该参数非空时，ipcList中的IPC都得是支持激活但未激活的设备
 * @param ipcList. IPC列表
 * @param completion 请求结束后回调，参数：1.请求错误信息 2.失败列表
 * @see SMBCloudSDKIPCToAddParam
 */
- (void)requestAddIPCListToNVRByNVRParam:(SMBCloudSDKDeviceParam *)nvrParam
                         activatePassword:(nullable NSString *)activatePassword
                                  ipcList:(NSArray<SMBCloudSDKIPCToAddParam *> *)ipcList
                               completion:(SMBCloudSDKDeviceAddManagerAddIPCListToNVRCompletion)completion
NS_SWIFT_NAME(requestAddIPCListToNVR(nvrParam:activatePassword:ipcList:completion:));

@end

NS_ASSUME_NONNULL_END

