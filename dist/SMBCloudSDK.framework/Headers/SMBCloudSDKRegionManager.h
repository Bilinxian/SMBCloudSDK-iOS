//
//  SMBCloudSDKRegionManager.h
//  Pods
//
//  Created by Li Weijian on 2024/1/17.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKError.h>
#import <SMBCloudSDK/SMBCloudSDKRegion.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^SMBCloudSDKRegionManagerCompletion)(__kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKRegionManagerAddRegionCompletion)(SMBCloudSDKRegion * _Nullable region, __kindof SMBCloudSDKError * error);
typedef void (^SMBCloudSDKRegionManagerGetRegionsCompletion)(NSArray<SMBCloudSDKRegion *> *regions, NSInteger totalRegionNum, __kindof SMBCloudSDKError * error);


@interface SMBCloudSDKRegionManager : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)shared NS_SWIFT_NAME(shared());

/**
 * @brief 添加分组
 * @discussion 错误码： -80202(项目不存在) -80203（父分组不存在） -80204（超过分组层级限制） -80209（分组总数超上限）
 * @param regionName 分组名，长度1~32，长度不合法或输入为全空格或带有特殊字符时（比如中文标点符号）会返回参数错误失败
 * @param order 分组在此层中的顺序，取值范围：[1, 2147483647]； 当传入值小于1时，默认添加到同层级最后面，即此时order值为同层级当前最大order+1
 * @param parentId 父分组索引，添加根分组时传入"0"
 * @param completion 请求结束后回调，参数：1.添加后生成的分组对象，当请求失败时返回的对象为nil 2.请求错误信息
 * @see SMBCloudSDKRegion
 */
- (void)requestAddRegionWithRegionName:(NSString *)regionName
                                     order:(NSInteger)order
                                  parentId:(NSString *)parentId
                                completion:(SMBCloudSDKRegionManagerAddRegionCompletion)completion
NS_SWIFT_NAME(requestAddRegion(regionName:order:parentId:completion:));

/**
 * @brief 编辑分组
 * @discussion 错误码： -80205(分组不存在) -80210（项目已存在同名分组）
 * @param newName 分组名，长度1~32，长度不合法或输入为全空格或带有特殊字符时（比如中文标点符号）会返回参数错误失败
 * @param region 需要修改名称的分组对象
 * @param completion 请求结束后回调，参数：1. 请求错误信息
 */
- (void)requestEditRegionWithNewName:(NSString *)newName
                              region:(SMBCloudSDKRegion *)region
                          completion:(SMBCloudSDKRegionManagerCompletion)completion
NS_SWIFT_NAME(requestEditRegion(newName:region:completion:));

/**
 * @brief 删除指定分组
 * @discussion 错误码： -80205(分组不存在)
 * @param regionId 需要删除的分组索引
 * @param completion 请求结束后回调，参数：1. 请求错误信息
 */
- (void)requestDeleteRegionWithRegionId:(NSString *)regionId
                             completion:(SMBCloudSDKRegionManagerCompletion)completion
NS_SWIFT_NAME(requestDeleteRegion(regionId:completion:));

/**
 * @brief 删除所有分组
 * @discussion 删除除默认分组外的所有分组
 * @param completion 请求结束后回调，参数：1. 请求错误信息
 */
- (void)requestDeleteAllRegionsWithCompletion:(SMBCloudSDKRegionManagerCompletion)completion
NS_SWIFT_NAME(requestDeleteAllRegions(completion:));

/**
 * @brief 交换平级分组顺序
 * @discussion 只能在同一父分组下交换平级分组，无法与默认分组及自身交换顺序。错误码： -80205(分组不存在) -80206（越级交换）
 * @param region 交换顺序的第一个分组对象
 * @param secondRegion 交互顺序的第二个分组对象
 * @param completion 请求结束后回调，参数：1. 请求错误信息
 */
- (void)requestSwitchRegionOrderWithRegion:(SMBCloudSDKRegion *)region
                              secondRegion:(SMBCloudSDKRegion *)secondRegion
                                completion:(SMBCloudSDKRegionManagerCompletion)completion
NS_SWIFT_NAME(requestSwitchRegionOrder(region:secondRegion:completion:));

/**
 * @brief 分页获取根分组
 * @discussion 错误码： -80202(项目不存在)
 * @param start 分页起始游标, 从0开始
 * @param limit 返回分组个数, 取值范围[1,50]
 * @param needDevNum 是否需要统计设备信息
 * @param completion 请求结束后回调，参数：1. 分组对象列表 2. 根分组总数 3. 请求错误信息
 * @see SMBCloudSDKRegion
 */
- (void)requestGetRootRegionsByPageWithStart:(NSInteger)start
                                       limit:(NSInteger)limit
                                  needDevNum:(BOOL)needDevNum
                                  completion:(SMBCloudSDKRegionManagerGetRegionsCompletion)completion
NS_SWIFT_NAME(requestGetRootRegionsByPage(start:limit:needDevNum:completion:));

/**
 * @brief 分页获取子分组
 * @discussion 错误码： -80202(项目不存在) -80205(分组不存在)
 * @param regionId 父分组ID
 * @param start 分页起始游标, 从0开始
 * @param limit 返回分组个数, 取值范围[1,50]
 * @param needDevNum 是否需要统计设备信息
 * @param completion 请求结束后回调，参数：1. 分组对象列表 2. 子分组总数 3. 请求错误信息
 * @see SMBCloudSDKRegion
 */
- (void)requestGetRegionChildrenByPageWithRegionId:(NSString *)regionId
                                             start:(NSInteger)start
                                             limit:(NSInteger)limit
                                        needDevNum:(BOOL)needDevNum
                                        completion:(SMBCloudSDKRegionManagerGetRegionsCompletion)completion
NS_SWIFT_NAME(requestGetRegionChildrenByPage(regionId:start:limit:needDevNum:completion:));

@end
NS_ASSUME_NONNULL_END
