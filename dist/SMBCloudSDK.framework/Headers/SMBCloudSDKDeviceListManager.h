//
//  SMBCloudSDKDeviceListManager.h
//  SMBCloudSDK
//
//  Created by qinshiji on 2024/2/5.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKError.h>
#import <SMBCloudSDK/SMBCloudSDKDevice.h>
#import <SMBCloudSDK/SMBCloudSDKChannelDevice.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceListFilterAndParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceListFilterOrParam.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceListSortType.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceParam.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^SMBCloudSDKDeviceListManagerGetDeviceListByPageCompletion)(NSInteger totalNum, NSArray<SMBCloudSDKDevice *> *deviceList, __kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKDeviceListManagerGetChannelListCompletion)(__kindof SMBCloudSDKError * error, NSInteger totalChannelNum, NSInteger conectedChannelNum, NSArray<SMBCloudSDKChannelDevice *> *channelList);
typedef void (^SMBCloudSDKDeviceListManagerGetDeviceDetailsCompletion)(__kindof SMBCloudSDKError * error,  SMBCloudSDKDevice * _Nullable device);

@interface SMBCloudSDKDeviceListManager : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)shared NS_SWIFT_NAME(shared());

/**
 * @brief 获取设备型应用下的设备列表
 * @discussion 该接口无法获取通道IPC的二维码。错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param start 分页起始序号（从0开始）
 * @param limit 每页获取的最大数量
 * @param hasChild 是否获取子设备，即NVR下的通道IPC
 * @param deviceTypes 设备类型列表，传SMBCloudSDKDeviceType的枚举值列表。可传空值，表示不按设备类型过滤
 * @param completion 请求结束后回调，参数：1.设备总数 2.获取到的该页设备列表对象 3.请求错误信息
 */
- (void)requestGetDeviceListInPublicAppicationByPage:(NSInteger)start
                                               limit:(NSInteger)limit
                                            hasChild:(BOOL)hasChild
                                         deviceTypes:(nullable NSSet <NSNumber *> *)deviceTypes
                                          completion:(SMBCloudSDKDeviceListManagerGetDeviceListByPageCompletion)completion
NS_SWIFT_NAME(requestGetDeviceListInPublicAppicationByPage(start:limit:hasChild:deviceTypes:completion:));

/**
 * @brief 获取项目型应用下的设备列表
 * @discussion 该接口无法获取通道IPC的二维码。 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param start 分页起始序号（从0开始）
 * @param limit 每页获取的最大数量
 * @param filterAnd 获取的数据要同时匹配filterAnd中的数据
 * @param filterOr 获取的数据要符合one of其中之一。可传空值
 * @param sortTypes 排序方式。可传空值。当传多组值时，数组第一位优先级最高，依次降低
 * @param completion 请求结束后回调，参数：1.设备总数 2.获取到的该页设备列表对象 3.请求错误信息
 * @see SMBCloudSDKDeviceListFilterAndParam
 * @see SMBCloudSDKDeviceListFilterOrParam
 * @see SMBCloudSDKDeviceListSortType
 */
- (void)requestGetDeviceListInProjectApplicationByPage:(NSInteger)start
                                                 limit:(NSInteger)limit
                                             filterAnd:(SMBCloudSDKDeviceListFilterAndParam *) filterAnd
                                              filterOr:(nullable SMBCloudSDKDeviceListFilterOrParam *) filterOr
                                             sortTypes:(nullable NSArray<SMBCloudSDKDeviceListSortType *> *)sortTypes
                                            completion:(SMBCloudSDKDeviceListManagerGetDeviceListByPageCompletion)completion
NS_SWIFT_NAME(requestGetDeviceListInProjectApplicationByPage(start:limit:filterAnd:filterOr:sortTypes:completion:));

/**
 * @brief 获取NVR通道列表
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param nvrParam NVR设备参数
 * @see SMBCloudSDKDeviceParam
 * @param completion 请求结束后回调，参数：1.请求错误信息 2.NVR总通道数 3.已连接通道数 4.通道设备列表
*/
- (void)requestNVRChannelListByNVRParam:(SMBCloudSDKDeviceParam *)nvrParam
                             completion:(SMBCloudSDKDeviceListManagerGetChannelListCompletion)completion
NS_SWIFT_NAME(requestNVRChannelList(nvrParam:copmpletion:));

/**
 * @brief 获取设备详情
 * @discussion 错误码： -40xxx（系统通用错误码），-80xxx（业务云错误码）
 * @param deviceParam 设备参数
 * @see SMBCloudSDKDeviceParam
 * @param completion 请求结束后回调，参数：1.请求错误信息 2.获取到的设备对象
*/
- (void)requestGetDeviceDetailsByDeviceParam:(SMBCloudSDKDeviceParam *)deviceParam
                                  completion:(SMBCloudSDKDeviceListManagerGetDeviceDetailsCompletion)completion
NS_SWIFT_NAME(requestGetDeviceDetails(deviceParam:copmpletion:));

@end


NS_ASSUME_NONNULL_END
