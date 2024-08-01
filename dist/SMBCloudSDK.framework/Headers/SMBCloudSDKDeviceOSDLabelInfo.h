//
//  SMBCloudSDKDeviceOSDLabelInfo.h
//  SMBCloudSDK
//
//  Created by W0116911 on 2024/2/27.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOSDEnum.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief  IPC 设备自定义字符串的 OSD 信息
*/
@interface SMBCloudSDKDeviceOSDLabelInfo : NSObject<NSCopying>

/**
 * @brief 起点X坐标，取值范围: [0, 10000]
 */
@property (nonatomic) NSInteger horizontalCoordinate;
/**
 * @brief 起点Y坐标，取值范围: [0, 10000]
 */
@property (nonatomic) NSInteger verticalCoordinate;
/**
 * @brief 显示状态
 * @see SMBCloudSDKDeviceOSDIfStatus
 */
@property (nonatomic) SMBCloudSDKDeviceOSDIfStatus showStatus;
/**
 * @brief 显示的内容
 */
@property (nonatomic, copy) NSString *text;
/**
 * @brief 自定义字符串名称。label_info_{labelId} ， nvr 通道只返回 label_info_1
 */
@property (nonatomic, copy) NSString *labelName;
/**
 * @brief 联动通道名称和设备名称状态
 * @see SMBCloudSDKDeviceOSDIfStatus
 */
@property (nonatomic) SMBCloudSDKDeviceOSDIfStatus linkToDevStatus;
/**
 * @brief 对齐方式， nvr 通道不会返回该参数
 * @see SMBSDKDeviceOSDLabelInfoAlignType
 */
@property (nonatomic, copy) SMBCloudSDKDeviceOSDLabelInfoAlignType alignType;

@end

NS_ASSUME_NONNULL_END
