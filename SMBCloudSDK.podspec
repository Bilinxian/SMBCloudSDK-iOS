
Pod::Spec.new do |s|
  s.name     = 'SMBCloudSDK'
  s.version  = '2.0.7'
  s.license  = 'MIT'
  s.summary  = 'TP-LINK商用云SDK'
  s.homepage = 'https://github.com/bilinxian/SMBCloudSDK-iOS'
  s.authors  = {'zhi wang' => 'wangzhi@cainiaomeishi.com'}
  s.source   = {:git => 'https://github.com/bilinxian/SMBCloudSDK-iOS.git',:tag => s.version,:submodules => true}
  s.requires_arc = true
  s.platform = :ios,'11.0'
  s.libraries = 'z'
  s.vendored_frameworks = 'dist/*.framework'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'GENERATE_INFOPLIST_FILE' => 'YES' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'GENERATE_INFOPLIST_FILE' => 'YES' }

end
