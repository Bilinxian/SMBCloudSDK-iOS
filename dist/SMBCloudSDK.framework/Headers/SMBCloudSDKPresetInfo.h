//
//  SMBCloudSDKPresetInfo.h
//  Pods
//
//  Created by yishuqi on 2024/3/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 预置点信息
 *
 */
@interface SMBCloudSDKPresetInfo : NSObject

/**@brief 预置点id**/
@property (nonatomic, copy, readonly) NSString *presetId;
/**@brief 预置点名称 **/
@property (nonatomic, copy, readonly) NSString *presetName;
/**@brief 预置点是否只读 **/
@property (nonatomic, readonly) BOOL isReadOnly;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
