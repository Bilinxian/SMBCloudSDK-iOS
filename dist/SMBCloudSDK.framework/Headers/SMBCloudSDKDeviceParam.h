//
//  SMBCloudSDKDeviceParam.h
//  Pods
//
//  Created by chenkairong on 2024/2/21.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDevice.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMBCloudSDKDeviceParam: NSObject

/**
 * @brief 设备二维码
 */
@property (nonatomic, copy, readonly) NSString *qrCode;

/**
 * @brief 设备mac地址
 */
@property (nonatomic, copy, readonly) NSString *mac;

/**
 * @brief 设备通道id
 */
@property (nonatomic, assign, readonly) NSInteger channelId;


- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 初始化方法（推荐使用）
 * @param device设备对象，若传入为NVR通道，会以parentQrCode/parentMac来构造参数。
 */
- (instancetype)initWithDevice:(SMBCloudSDKDevice *)device;

/**
 * @brief 初始化方法（传递的参数来源于设备列表获取到的对象数据）
 * @param qrCode  设备二维码，对于通道设备，qrCode应传父设备的qrCode
 * @param channelId 设备通道id，直连IPC必须传1，NVR必须传-1，通道设备传对应通道ID
 */
- (instancetype)initWithQrCode:(NSString *)qrCode
                     channelId:(NSInteger)channelId;

/**
 * @brief 初始化方法（传递的参数来源于设备列表获取到的对象数据）
 * @param mac 设备mac地址，对于通道设备，mac应传父设备的mac
 * @param channelId 设备通道id，直连IPC必须传1，NVR必须传-1，通道设备传对应通道ID
 */
- (instancetype)initWithMac:(NSString *)mac
                  channelId:(NSInteger)channelId;

/**
 * @brief 获取直连IPC或NVR的默认channelId（通道IPC无法通过此方法获取其channelId）
 * @param deviceType 设备类型
 *
 * @return NSInteger 设备默认channelId
 */
+ (NSInteger)getDefaultChannelIdWithDeviceType:(SMBCloudSDKDeviceType)deviceType
NS_SWIFT_NAME(getDefaultChannelId(deviceType:));

@end

NS_ASSUME_NONNULL_END
