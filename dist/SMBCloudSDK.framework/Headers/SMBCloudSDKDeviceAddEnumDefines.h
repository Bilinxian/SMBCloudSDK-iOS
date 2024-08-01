//
//  SMBCloudSDKDeviceAddEnumDefines.h
//  Pods
//
//  Created by litao on 2024/1/30.
//

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 设备子类型
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKDeviceSubType) {
    SMBCloudSDKDeviceSubTypeUnknown = -1, // 未知类型
    SMBCloudSDKDeviceSubTypeIPC     = 0,  // IPC类型
    SMBCloudSDKDeviceSubTypeNVR     = 1,  // NVR类型
};

/**
 * @brief 设备激活类型
 */
typedef NS_ENUM(NSUInteger, SMBCloudSDKDeviceActivateType) {
    SMBCloudSDKDeviceActivateTypeNotSupport   = 0, // 不支持激活
    SMBCloudSDKDeviceActivateTypeUnactivated  = 1, // 未激活
    SMBCloudSDKDeviceActivateTypeActivated    = 2, // 已激活
};

/**
 * @brief 配网WIFI认证类型
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKOnboardWiFiAuthType) {
    /** @brief 配网WIFI认证类型: 未知类型 */
    SMBCloudSDKOnboardWiFiAuthTypeUnknown = -1,
    /** @brief 配网WIFI认证类型: 无认证 */
    SMBCloudSDKOnboardWiFiAuthTypeNone,
    /** @brief 配网WIFI认证类型: Wep认证类型 */
    SMBCloudSDKOnboardWiFiAuthTypeWep,
    /** @brief 配网WIFI认证类型: WpaPsk认证类型 */
    SMBCloudSDKOnboardWiFiAuthTypeWpaPsk,
    /** @brief 配网WIFI认证类型: Wpa2Psk认证类型 */
    SMBCloudSDKOnboardWiFiAuthTypeWpa2Psk,
    /** @brief 配网WIFI认证类型: WpaWpa2Psk认证类型 */
    SMBCloudSDKOnboardWiFiAuthTypeWpaWpa2Psk,
};

/**
 * @brief 配网WIFI加密类型
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKOnboardWiFiEncryptType) {
    /** @brief 配网WIFI加密类型: 未知类型 */
    SMBCloudSDKOnboardWiFiEncryptTypeUnknown = -1,
    /** @brief 配网WIFI加密类型: 无加密 */
    SMBCloudSDKOnboardWiFiEncryptTypeNone,
    /** @brief 配网WIFI加密类型:Tkip加密类型 */
    SMBCloudSDKOnboardWiFiEncryptTypeTkip,
    /** @brief 配网WIFI加密类型: Ccmp加密类型 */
    SMBCloudSDKOnboardWiFiEncryptTypeCcmp,
    /** @brief 配网WIFI加密类型:CcmpTkip加密类型*/
    SMBCloudSDKOnboardWiFiEncryptTypeCcmpTkip,
};

/**
 * @brief 配网连接状态
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKOnboardConnectStatus) {
    /** @brief 配网连接状态: 正在连接*/
    SMBCloudSDKOnboardConnectStatusConnecting  = 1,
    /** @brief 配网连接状态: 已连接*/
    SMBCloudSDKOnboardConnectStatusConnected  = 0,
    /** @brief 配网连接状态: 通用连接失败*/
    SMBCloudSDKOnboardConnectStatusFailGeneral = -1,
    /** @brief 配网连接状态: 认证失败*/
    SMBCloudSDKOnboardConnectStatusFailAuth    = -2,
    /** @brief 配网连接状态: DHCP设置失败*/
    SMBCloudSDKOnboardConnectStatusFailDHCP    = -3,
};

/**
 * @brief 设备特征类型
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKDeviceFeatureType) {
    /** @brief 设备特征类型: 默认类型*/
    SMBCloudSDKDeviceFeatureTypeDefault = 0,
    /** @brief 设备特征类型: 可配置密码*/
    SMBCloudSDKDeviceFeatureTypeRandomPwd = 7,
    /** @brief 设备特征类型: 可配置用户名*/
    SMBCloudSDKDeviceFeatureTypeConfigurableUsername = 10
};

/**
 * @brief 声波版本
 */
typedef NS_ENUM(NSInteger, SMBCloudSDKAudioVersionType) {
    /** @brief 声波版本: 旧版本，旧设备、新设备均能识别*/
    SMBCloudSDKAudioVersionTypeOld = 1,
    /** @brief 声波版本: 新版本，旧设备无法识别、新设备可识别*/
    SMBCloudSDKAudioVersionTypeNew = 2,
};

NS_ASSUME_NONNULL_END
