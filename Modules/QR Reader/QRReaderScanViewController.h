#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

#import "DecoderDelegate.h"

@protocol QRReaderScanDelegate;
@class QRReaderOverlayView;
@class FormatReader;

@interface QRReaderScanViewController : UIViewController <AVCaptureVideoDataOutputSampleBufferDelegate,DecoderDelegate> {
    id<QRReaderScanDelegate> _scanDelegate;
    QRReaderOverlayView *_overlayView;
    UILabel *adviceLabel;
    BOOL _isCaptureActive;
    BOOL _decodedResult;
    
    AVCaptureSession *_captureSession;
    AVCaptureVideoPreviewLayer *_previewLayer;
    FormatReader *_reader;
    
    UIButton *_cancelButton;
}

@property (nonatomic,retain) id<QRReaderScanDelegate> scanDelegate;
@property (nonatomic,retain,readonly) IBOutlet QRReaderOverlayView *overlayView;
@property (nonatomic,retain,readonly) UILabel *adviceLabel;
@property (nonatomic,readonly) BOOL isCaptureActive;
@property (nonatomic,retain) FormatReader *reader;

+ (FormatReader*)defaultReader;
@end

@protocol QRReaderScanDelegate <NSObject>
@required
- (void)scanView:(QRReaderScanViewController*)scanView
   didScanResult:(NSString*)result
       fromImage:(UIImage*)image;
- (void)scanViewDidCancel:(QRReaderScanViewController*)scanView;
@end

