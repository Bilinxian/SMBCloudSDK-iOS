//
//  SMBCloudSDKRegion.h
//  Pods
//
//  Created by Li Weijian on 2024/1/17.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKDeviceOverview.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 分组结构信息
*/
@interface SMBCloudSDKRegion: NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 分组索引
*/
@property (nonatomic, copy, readonly) NSString *regionId;
/**
 * @brief 分组名称
*/
@property (nonatomic, copy, readonly) NSString *regionName;
/**
 * @brief 分组层级
*/
@property (nonatomic, assign, readonly) NSInteger level;
/**
 * @brief 分组层级内顺序
*/
@property (nonatomic, assign, readonly) NSInteger order;
/**
 * @brief 父分组索引
*/
@property (nonatomic, copy, readonly) NSString *parentRegionId;
/**
 * @brief 是否还有子分组
*/
@property (nonatomic, assign, readonly) BOOL hasChildren;
/**
 * @brief 是否为默认分组
*/
@property (nonatomic, assign) BOOL isDefaultRegion;
/**
 * @brief 总设备数，包含所有系统类型设备数量，若获取单个系统类型设备数量，需使用deviceNumMap
*/
@property (nonatomic, assign, readonly) NSInteger totalDevNum;
/**
 * @brief 总在线设备数，包含所有系统类型设备数量，若获取单个系统类型设备数量，需使用deviceNumMap
*/
@property (nonatomic, assign, readonly) NSInteger totalDevOnlineNum;
/**
 * @brief 各系统设备数量
 * @discussion 键为系统类型，包括vms(安防设备)、nms（网络设备）、nbs（广播设备）、evcs（充电设备）、parking（停车设备）、ams（门禁设备），值为设备的数量信息
 * @see SMBCloudSDKDeviceOverview
*/
@property (nonatomic, copy, readonly) NSDictionary<NSString *, SMBCloudSDKDeviceOverview *> *deviceNumMap;

@end

NS_ASSUME_NONNULL_END
