source 'https://github.com/CocoaPods/Specs.git'

target "FriendWho" do
  pod 'FBSDKCoreKit'
  pod 'FBSDKLoginKit'
  pod 'FBSDKShareKit'
end

def test_pods
  pod 'Specta', '~> 1.0'
  pod 'Expecta', '~> 1.0'
  pod 'Expecta+Collections'                                              
  pod 'Swizzlean', '~> 0.2'
  pod 'KIF', '~> 3.0'
  pod 'KIFViewControllerActions'
end

target "FriendWhoTests" do
  test_pods
end

target "FriendWhoUITests" do
  test_pods
end
