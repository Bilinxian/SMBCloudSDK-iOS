//
//  SMBCloudSDKPlayerStreamParam.h
//  Pods
//
//  Created by yuanwq on 2023/10/24.
//

#import <Foundation/Foundation.h>
#import <SMBCloudSDK/SMBCloudSDKPlayerDefines.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief （预览、回放、对讲）音视频流参数
 */
@interface SMBCloudSDKPlayerStreamParam : NSObject

/**
 * @brief 平台sdk预览、回放、对讲的地址信息，将此传递给sdk组件以播放设备画面
 */
@property (nonatomic, copy) NSString *streamUrl;

/**
 * @brief 传输协议版本。通过设备能力集接口获取
 */
@property (nonatomic, copy) NSString *streamVersion;

/**
 * @brief relay协议版本：取值1.3, 2.0。通过设备能力集接口获取
 */
@property (nonatomic, copy) NSString *relayVersion;

/**
 * @brief 清晰度
 * @see SMBCloudSDKPlayerResolution
 */
@property (nonatomic, assign) SMBCloudSDKPlayerResolution resolution;

- (instancetype)init NS_UNAVAILABLE;

/**
 * @brief 初始化方法
 * @param streamUrl  平台sdk预览、回放、对讲的地址信息
 * @param streamVersion 传输协议版本
 * @param relayVersion relay协议版本
 * @param resolution 清晰度
 * @see SMBCloudSDKPlayerResolution
 */
- (instancetype)initWithStreamUrl:(NSString *)streamUrl
                    streamVersion:(NSString *)streamVersion
                     relayVersion:(NSString *)relayVersion
                       resolution:(SMBCloudSDKPlayerResolution)resolution;

/**
 * @brief 初始化方法（清晰度默认为SMBCloudSDKPlayerResolutionVGA）
 * @param streamUrl  平台sdk预览、回放、对讲的地址信息
 * @param streamVersion 传输协议版本
 * @param relayVersion relay协议版本
 */
- (instancetype)initWithStreamUrl:(NSString *)streamUrl
                    streamVersion:(NSString *)streamVersion
                     relayVersion:(NSString *)relayVersion;
@end

NS_ASSUME_NONNULL_END
