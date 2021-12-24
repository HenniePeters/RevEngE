// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GIFImage.pas' rev: 6.00

#ifndef GIFImageHPP
#define GIFImageHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Gifimage
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TGIFVersion { gvUnknown, gv87a, gv89a };
#pragma option pop

typedef char TGIFVersionRec[3];

class DELPHICLASS GIFException;
class PASCALIMPLEMENTATION GIFException : public Graphics::EInvalidGraphic 
{
	typedef Graphics::EInvalidGraphic inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall GIFException(const AnsiString Msg) : Graphics::EInvalidGraphic(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall GIFException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Graphics::EInvalidGraphic(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall GIFException(int Ident)/* overload */ : Graphics::EInvalidGraphic(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall GIFException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Graphics::EInvalidGraphic(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall GIFException(const AnsiString Msg, int AHelpContext) : Graphics::EInvalidGraphic(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall GIFException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Graphics::EInvalidGraphic(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall GIFException(int Ident, int AHelpContext)/* overload */ : Graphics::EInvalidGraphic(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall GIFException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Graphics::EInvalidGraphic(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~GIFException(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TGIFSeverity { gsInfo, gsWarning, gsError };
#pragma option pop

class DELPHICLASS TGIFItem;
class DELPHICLASS TGIFImage;
class DELPHICLASS TGIFImageList;
class DELPHICLASS TGIFList;
class PASCALIMPLEMENTATION TGIFList : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	TGIFItem* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TList* FItems;
	TGIFImage* FImage;
	
protected:
	TGIFItem* __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, TGIFItem* Item);
	int __fastcall GetCount(void);
	virtual void __fastcall Warning(TGIFSeverity Severity, AnsiString Message);
	
public:
	__fastcall TGIFList(TGIFImage* Image);
	__fastcall virtual ~TGIFList(void);
	int __fastcall Add(TGIFItem* Item);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	void __fastcall Exchange(int Index1, int Index2);
	TGIFItem* __fastcall First(void);
	int __fastcall IndexOf(TGIFItem* Item);
	void __fastcall Insert(int Index, TGIFItem* Item);
	TGIFItem* __fastcall Last(void);
	void __fastcall Move(int CurIndex, int NewIndex);
	int __fastcall Remove(TGIFItem* Item);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream, System::TObject* Parent) = 0 ;
	__property TGIFItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property int Count = {read=GetCount, nodefault};
	__property Classes::TList* List = {read=FItems};
	__property TGIFImage* Image = {read=FImage};
};


class DELPHICLASS TGIFSubImage;
class PASCALIMPLEMENTATION TGIFImageList : public TGIFList 
{
	typedef TGIFList inherited;
	
public:
	TGIFSubImage* operator[](int Index) { return SubImages[Index]; }
	
protected:
	TGIFSubImage* __fastcall GetImage(int Index);
	void __fastcall SetImage(int Index, TGIFSubImage* SubImage);
	
public:
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream, System::TObject* Parent);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	__property TGIFSubImage* SubImages[int Index] = {read=GetImage, write=SetImage/*, default*/};
public:
	#pragma option push -w-inl
	/* TGIFList.Create */ inline __fastcall TGIFImageList(TGIFImage* Image) : TGIFList(Image) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TGIFList.Destroy */ inline __fastcall virtual ~TGIFImageList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGIFHeader;
class PASCALIMPLEMENTATION TGIFItem : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TGIFImage* FGIFImage;
	
protected:
	virtual TGIFVersion __fastcall GetVersion(void);
	virtual void __fastcall Warning(TGIFSeverity Severity, AnsiString Message);
	
public:
	__fastcall virtual TGIFItem(TGIFImage* GIFImage);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream) = 0 ;
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream) = 0 ;
	virtual void __fastcall SaveToFile(const AnsiString Filename);
	virtual void __fastcall LoadFromFile(const AnsiString Filename);
	__property TGIFVersion Version = {read=GetVersion, nodefault};
	__property TGIFImage* Image = {read=FGIFImage};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGIFItem(void) { }
	#pragma option pop
	
};


#pragma pack(push, 1)
struct TLogicalScreenDescriptor
{
	Word ScreenWidth;
	Word ScreenHeight;
	Byte PackedFields;
	Byte BackgroundColorIndex;
	Byte AspectRatio;
} ;
#pragma pack(pop)

class DELPHICLASS TGIFColorMap;
#pragma pack(push, 1)
struct TGIFColor
{
	Byte Red;
	Byte Green;
	Byte Blue;
} ;
#pragma pack(pop)

typedef TGIFColor TColorMap[256];

typedef TGIFColor *PColorMap;

#pragma pack(push, 4)
struct TUsageCount
{
	int Count;
	int Index;
} ;
#pragma pack(pop)

typedef TUsageCount TColormapHistogram[256];

typedef Byte TColormapReverse[256];

class PASCALIMPLEMENTATION TGIFColorMap : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	Graphics::TColor operator[](int Index) { return Colors[Index]; }
	
private:
	TGIFColor *FColorMap;
	int FCount;
	int FCapacity;
	bool FOptimized;
	
protected:
	Graphics::TColor __fastcall GetColor(int Index);
	void __fastcall SetColor(int Index, Graphics::TColor Value);
	int __fastcall GetBitsPerPixel(void);
	bool __fastcall DoOptimize(void);
	void __fastcall SetCapacity(int Size);
	virtual void __fastcall Warning(TGIFSeverity Severity, AnsiString Message) = 0 ;
	virtual void __fastcall BuildHistogram(TUsageCount * Histogram) = 0 ;
	virtual void __fastcall MapImages(Byte * Map) = 0 ;
	
public:
	__fastcall TGIFColorMap(void);
	__fastcall virtual ~TGIFColorMap(void);
	/*         class method */ static TGIFColor __fastcall Color2RGB(TMetaClass* vmt, Graphics::TColor Color);
	/*         class method */ static Graphics::TColor __fastcall RGB2Color(TMetaClass* vmt, TGIFColor Color);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall LoadFromStream(Classes::TStream* Stream, int Count);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall IndexOf(Graphics::TColor Color);
	int __fastcall Add(Graphics::TColor Color);
	int __fastcall AddUnique(Graphics::TColor Color);
	void __fastcall Delete(int Index);
	void __fastcall Clear(void);
	virtual bool __fastcall Optimize(void) = 0 ;
	virtual void __fastcall Changed(void) = 0 ;
	void __fastcall ImportPalette(HPALETTE Palette);
	void __fastcall ImportColorTable(void * Pal, int Count);
	void __fastcall ImportDIBColors(HDC Handle);
	void __fastcall ImportColorMap(const TGIFColor * Map, int Count);
	HPALETTE __fastcall ExportPalette(void);
	__property Graphics::TColor Colors[int Index] = {read=GetColor, write=SetColor/*, default*/};
	__property PColorMap Data = {read=FColorMap};
	__property int Count = {read=FCount, nodefault};
	__property bool Optimized = {read=FOptimized, write=FOptimized, nodefault};
	__property int BitsPerPixel = {read=GetBitsPerPixel, nodefault};
};


class PASCALIMPLEMENTATION TGIFHeader : public TGIFItem 
{
	typedef TGIFItem inherited;
	
private:
	#pragma pack(push, 1)
	TLogicalScreenDescriptor FLogicalScreenDescriptor;
	#pragma pack(pop)
	
	TGIFColorMap* FColorMap;
	void __fastcall Prepare(void);
	
protected:
	virtual TGIFVersion __fastcall GetVersion(void);
	Graphics::TColor __fastcall GetBackgroundColor(void);
	void __fastcall SetBackgroundColor(Graphics::TColor Color);
	void __fastcall SetBackgroundColorIndex(Byte Index);
	int __fastcall GetBitsPerPixel(void);
	int __fastcall GetColorResolution(void);
	
public:
	__fastcall virtual TGIFHeader(TGIFImage* GIFImage);
	__fastcall virtual ~TGIFHeader(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall Clear(void);
	__property TGIFVersion Version = {read=GetVersion, nodefault};
	__property Word Width = {read=FLogicalScreenDescriptor.ScreenWidth, write=FLogicalScreenDescriptor.ScreenWidth, nodefault};
	__property Word Height = {read=FLogicalScreenDescriptor.ScreenHeight, write=FLogicalScreenDescriptor.ScreenHeight, nodefault};
	__property Byte BackgroundColorIndex = {read=FLogicalScreenDescriptor.BackgroundColorIndex, write=SetBackgroundColorIndex, nodefault};
	__property Graphics::TColor BackgroundColor = {read=GetBackgroundColor, write=SetBackgroundColor, nodefault};
	__property Byte AspectRatio = {read=FLogicalScreenDescriptor.AspectRatio, write=FLogicalScreenDescriptor.AspectRatio, nodefault};
	__property TGIFColorMap* ColorMap = {read=FColorMap};
	__property int BitsPerPixel = {read=GetBitsPerPixel, nodefault};
	__property int ColorResolution = {read=GetColorResolution, nodefault};
};


#pragma option push -b-
enum TGIFDrawOption { goAsync, goTransparent, goAnimate, goLoop, goLoopContinously, goValidateCanvas, goDirectDraw, goClearOnLoop, goTile, goDither, goAutoDither };
#pragma option pop

typedef Set<TGIFDrawOption, goAsync, goAutoDither>  TGIFDrawOptions;

#pragma option push -b-
enum TColorReduction { rmNone, rmWindows20, rmWindows256, rmWindowsGray, rmMonochrome, rmGrayScale, rmNetscape, rmQuantize, rmQuantizeWindows, rmPalette };
#pragma option pop

#pragma option push -b-
enum TDitherMode { dmNearest, dmFloydSteinberg, dmStucki, dmSierra, dmJaJuNI, dmSteveArche, dmBurkes };
#pragma option pop

#pragma option push -b-
enum TGIFCompression { gcLZW, gcRLE };
#pragma option pop

typedef void __fastcall (__closure *TGIFWarning)(System::TObject* Sender, TGIFSeverity Severity, AnsiString Message);

class DELPHICLASS TGIFPainter;
#pragma option push -b-
enum TDisposalMethod { dmNone, dmNoDisposal, dmBackground, dmPrevious };
#pragma option pop

typedef TGIFPainter* *PGIFPainter;

class PASCALIMPLEMENTATION TGIFPainter : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	TGIFImage* FImage;
	Graphics::TCanvas* FCanvas;
	#pragma pack(push, 1)
	Types::TRect FRect;
	#pragma pack(pop)
	
	TGIFDrawOptions FDrawOptions;
	int FAnimationSpeed;
	int FActiveImage;
	TDisposalMethod Disposal;
	TDisposalMethod OldDisposal;
	Graphics::TBitmap* BackupBuffer;
	Graphics::TBitmap* FrameBuffer;
	Graphics::TBitmap* Background;
	HDC ValidateDC;
	bool DoRestart;
	bool FStarted;
	TGIFPainter* *PainterRef;
	unsigned FEventHandle;
	Sysutils::Exception* ExceptObject;
	void *ExceptAddress;
	Classes::TNotifyEvent FEvent;
	Classes::TNotifyEvent FOnStartPaint;
	Classes::TNotifyEvent FOnPaint;
	Classes::TNotifyEvent FOnAfterPaint;
	Classes::TNotifyEvent FOnLoop;
	Classes::TNotifyEvent FOnEndPaint;
	void __fastcall DoOnTerminate(System::TObject* Sender);
	void __fastcall DoSynchronize(Classes::TThreadMethod Method);
	void __fastcall DoPaintFrame(void);
	void __fastcall DoPaint(void);
	void __fastcall DoEvent(void);
	void __fastcall SetActiveImage(const int Value);
	
protected:
	virtual void __fastcall Execute(void);
	void __fastcall SetAnimationSpeed(int Value);
	
public:
	__fastcall TGIFPainter(TGIFImage* AImage, Graphics::TCanvas* ACanvas, const Types::TRect &ARect, TGIFDrawOptions Options);
	__fastcall TGIFPainter(PGIFPainter Painter, TGIFImage* AImage, Graphics::TCanvas* ACanvas, const Types::TRect &ARect, TGIFDrawOptions Options);
	__fastcall virtual ~TGIFPainter(void);
	void __fastcall Start(void);
	void __fastcall Stop(void);
	void __fastcall Restart(void);
	__property TGIFImage* Image = {read=FImage};
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	__property Types::TRect Rect = {read=FRect, write=FRect};
	__property TGIFDrawOptions DrawOptions = {read=FDrawOptions, write=FDrawOptions, nodefault};
	__property int AnimationSpeed = {read=FAnimationSpeed, write=SetAnimationSpeed, nodefault};
	__property bool Started = {read=FStarted, nodefault};
	__property int ActiveImage = {read=FActiveImage, write=SetActiveImage, nodefault};
	__property Classes::TNotifyEvent OnStartPaint = {read=FOnStartPaint, write=FOnStartPaint};
	__property Classes::TNotifyEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property Classes::TNotifyEvent OnAfterPaint = {read=FOnAfterPaint, write=FOnAfterPaint};
	__property Classes::TNotifyEvent OnLoop = {read=FOnLoop, write=FOnLoop};
	__property Classes::TNotifyEvent OnEndPaint = {read=FOnEndPaint, write=FOnEndPaint};
	__property unsigned EventHandle = {read=FEventHandle, nodefault};
};


#pragma option push -b-
enum TGIFOptimizeOption { ooCrop, ooMerge, ooCleanup, ooColorMap, ooReduceColors };
#pragma option pop

typedef Set<TGIFOptimizeOption, ooCrop, ooReduceColors>  TGIFOptimizeOptions;

class PASCALIMPLEMENTATION TGIFImage : public Graphics::TGraphic 
{
	typedef Graphics::TGraphic inherited;
	
private:
	bool IsDrawing;
	bool IsInsideGetPalette;
	TGIFImageList* FImages;
	TGIFHeader* FHeader;
	HPALETTE FGlobalPalette;
	Classes::TThreadList* FPainters;
	TGIFDrawOptions FDrawOptions;
	TColorReduction FColorReduction;
	int FReductionBits;
	TDitherMode FDitherMode;
	TGIFCompression FCompression;
	TGIFWarning FOnWarning;
	Graphics::TBitmap* FBitmap;
	TGIFPainter* FDrawPainter;
	Classes::TThreadPriority FThreadPriority;
	int FAnimationSpeed;
	int FForceFrame;
	Graphics::TColor FDrawBackgroundColor;
	Classes::TNotifyEvent FOnStartPaint;
	Classes::TNotifyEvent FOnPaint;
	Classes::TNotifyEvent FOnAfterPaint;
	Classes::TNotifyEvent FOnLoop;
	Classes::TNotifyEvent FOnEndPaint;
	bool __fastcall GetAnimate(void);
	void __fastcall SetAnimate(const bool Value);
	void __fastcall SetForceFrame(const int Value);
	
protected:
	virtual int __fastcall GetHeight(void);
	virtual void __fastcall SetHeight(int Value);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall SetWidth(int Value);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	TGIFPainter* __fastcall InternalPaint(PGIFPainter Painter, Graphics::TCanvas* ACanvas, const Types::TRect &Rect, TGIFDrawOptions Options);
	virtual void __fastcall Draw(Graphics::TCanvas* ACanvas, const Types::TRect &Rect);
	virtual bool __fastcall Equals(Graphics::TGraphic* Graphic);
	virtual HPALETTE __fastcall GetPalette(void);
	virtual void __fastcall SetPalette(HPALETTE Value);
	virtual bool __fastcall GetEmpty(void);
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	bool __fastcall GetIsTransparent(void);
	TGIFVersion __fastcall GetVersion(void);
	int __fastcall GetColorResolution(void);
	int __fastcall GetBitsPerPixel(void);
	Byte __fastcall GetBackgroundColorIndex(void);
	void __fastcall SetBackgroundColorIndex(const Byte Value);
	Graphics::TColor __fastcall GetBackgroundColor(void);
	void __fastcall SetBackgroundColor(const Graphics::TColor Value);
	Byte __fastcall GetAspectRatio(void);
	void __fastcall SetAspectRatio(const Byte Value);
	void __fastcall SetDrawOptions(TGIFDrawOptions Value);
	void __fastcall SetAnimationSpeed(int Value);
	void __fastcall SetReductionBits(int Value);
	void __fastcall NewImage(void);
	Graphics::TBitmap* __fastcall GetBitmap(void);
	Graphics::TBitmap* __fastcall NewBitmap(void);
	void __fastcall FreeBitmap(void);
	TGIFColorMap* __fastcall GetColorMap(void);
	bool __fastcall GetDoDither(void);
	__property TGIFPainter* DrawPainter = {read=FDrawPainter};
	__property bool DoDither = {read=GetDoDither, nodefault};
	void __fastcall FixHeaderWidthHeight(void);
	
public:
	__fastcall virtual TGIFImage(void);
	__fastcall virtual ~TGIFImage(void);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall LoadFromResourceName(unsigned Instance, const AnsiString ResName);
	int __fastcall Add(Classes::TPersistent* Source);
	void __fastcall Pack(void);
	void __fastcall OptimizeColorMap(void);
	void __fastcall Optimize(TGIFOptimizeOptions Options, TColorReduction ColorReduction, TDitherMode DitherMode, int ReductionBits);
	void __fastcall Clear(void);
	void __fastcall StopDraw(void);
	TGIFPainter* __fastcall Paint(Graphics::TCanvas* ACanvas, const Types::TRect &Rect, TGIFDrawOptions Options);
	void __fastcall PaintStart(void);
	void __fastcall PaintPause(void);
	void __fastcall PaintStop(void);
	void __fastcall PaintResume(void);
	void __fastcall PaintRestart(void);
	virtual void __fastcall Warning(System::TObject* Sender, TGIFSeverity Severity, AnsiString Message);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall LoadFromClipboardFormat(Word AFormat, unsigned AData, HPALETTE APalette);
	virtual void __fastcall SaveToClipboardFormat(Word &AFormat, unsigned &AData, HPALETTE &APalette);
	__property TGIFColorMap* GlobalColorMap = {read=GetColorMap};
	__property TGIFVersion Version = {read=GetVersion, nodefault};
	__property TGIFImageList* Images = {read=FImages};
	__property int ColorResolution = {read=GetColorResolution, nodefault};
	__property int BitsPerPixel = {read=GetBitsPerPixel, nodefault};
	__property Byte BackgroundColorIndex = {read=GetBackgroundColorIndex, write=SetBackgroundColorIndex, nodefault};
	__property Graphics::TColor BackgroundColor = {read=GetBackgroundColor, write=SetBackgroundColor, nodefault};
	__property Byte AspectRatio = {read=GetAspectRatio, write=SetAspectRatio, nodefault};
	__property TGIFHeader* Header = {read=FHeader};
	__property bool IsTransparent = {read=GetIsTransparent, nodefault};
	__property TGIFDrawOptions DrawOptions = {read=FDrawOptions, write=SetDrawOptions, nodefault};
	__property Graphics::TColor DrawBackgroundColor = {read=FDrawBackgroundColor, write=FDrawBackgroundColor, nodefault};
	__property TColorReduction ColorReduction = {read=FColorReduction, write=FColorReduction, nodefault};
	__property int ReductionBits = {read=FReductionBits, write=SetReductionBits, nodefault};
	__property TDitherMode DitherMode = {read=FDitherMode, write=FDitherMode, nodefault};
	__property TGIFCompression Compression = {read=FCompression, write=FCompression, nodefault};
	__property int AnimationSpeed = {read=FAnimationSpeed, write=SetAnimationSpeed, nodefault};
	__property bool Animate = {read=GetAnimate, write=SetAnimate, nodefault};
	__property int ForceFrame = {read=FForceFrame, write=SetForceFrame, nodefault};
	__property Classes::TThreadList* Painters = {read=FPainters};
	__property Classes::TThreadPriority ThreadPriority = {read=FThreadPriority, write=FThreadPriority, nodefault};
	__property Graphics::TBitmap* Bitmap = {read=GetBitmap};
	__property TGIFWarning OnWarning = {read=FOnWarning, write=FOnWarning};
	__property Classes::TNotifyEvent OnStartPaint = {read=FOnStartPaint, write=FOnStartPaint};
	__property Classes::TNotifyEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property Classes::TNotifyEvent OnAfterPaint = {read=FOnAfterPaint, write=FOnAfterPaint};
	__property Classes::TNotifyEvent OnLoop = {read=FOnLoop, write=FOnLoop};
	__property Classes::TNotifyEvent OnEndPaint = {read=FOnEndPaint, write=FOnEndPaint};
};



typedef Byte TGIFExtensionType;

typedef TMetaClass*TGIFExtensionClass;

class DELPHICLASS TGIFExtension;
class PASCALIMPLEMENTATION TGIFExtension : public TGIFItem 
{
	typedef TGIFItem inherited;
	
private:
	TGIFSubImage* FSubImage;
	
protected:
	virtual Byte __fastcall GetExtensionType(void) = 0 ;
	virtual TGIFVersion __fastcall GetVersion(void);
	Byte __fastcall DoReadFromStream(Classes::TStream* Stream);
	/*         class method */ static void __fastcall RegisterExtension(TMetaClass* vmt, Byte elabel, TMetaClass* eClass);
	/*         class method */ static TMetaClass* __fastcall FindExtension(TMetaClass* vmt, Classes::TStream* Stream);
	/* virtual class method */ virtual TMetaClass* __fastcall FindSubExtension(TMetaClass* vmt, Classes::TStream* Stream);
	
public:
	__fastcall virtual TGIFExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFExtension(void);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	__property Byte ExtensionType = {read=GetExtensionType, nodefault};
	__property TGIFSubImage* SubImage = {read=FSubImage};
};


class DELPHICLASS TGIFExtensionList;
class PASCALIMPLEMENTATION TGIFExtensionList : public TGIFList 
{
	typedef TGIFList inherited;
	
public:
	TGIFExtension* operator[](int Index) { return Extensions[Index]; }
	
protected:
	TGIFExtension* __fastcall GetExtension(int Index);
	void __fastcall SetExtension(int Index, TGIFExtension* Extension);
	
public:
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream, System::TObject* Parent);
	__property TGIFExtension* Extensions[int Index] = {read=GetExtension, write=SetExtension/*, default*/};
public:
	#pragma option push -w-inl
	/* TGIFList.Create */ inline __fastcall TGIFExtensionList(TGIFImage* Image) : TGIFList(Image) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TGIFList.Destroy */ inline __fastcall virtual ~TGIFExtensionList(void) { }
	#pragma option pop
	
};


#pragma pack(push, 1)
struct TImageDescriptor
{
	Byte Separator;
	Word Left;
	Word Top;
	Word Width;
	Word Height;
	Byte PackedFields;
} ;
#pragma pack(pop)

class DELPHICLASS TGIFGraphicControlExtension;
#pragma pack(push, 1)
struct TGIFGCERec
{
	Byte BlockSize;
	Byte PackedFields;
	Word DelayTime;
	Byte TransparentColorIndex;
	Byte Terminator;
} ;
#pragma pack(pop)

class PASCALIMPLEMENTATION TGIFGraphicControlExtension : public TGIFExtension 
{
	typedef TGIFExtension inherited;
	
private:
	#pragma pack(push, 1)
	TGIFGCERec FGCExtension;
	#pragma pack(pop)
	
	
protected:
	virtual Byte __fastcall GetExtensionType(void);
	bool __fastcall GetTransparent(void);
	void __fastcall SetTransparent(bool Value);
	Graphics::TColor __fastcall GetTransparentColor(void);
	void __fastcall SetTransparentColor(Graphics::TColor Color);
	Byte __fastcall GetTransparentColorIndex(void);
	void __fastcall SetTransparentColorIndex(Byte Value);
	Word __fastcall GetDelay(void);
	void __fastcall SetDelay(Word Value);
	bool __fastcall GetUserInput(void);
	void __fastcall SetUserInput(bool Value);
	TDisposalMethod __fastcall GetDisposal(void);
	void __fastcall SetDisposal(TDisposalMethod Value);
	
public:
	__fastcall virtual TGIFGraphicControlExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFGraphicControlExtension(void);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	__property Word Delay = {read=GetDelay, write=SetDelay, nodefault};
	__property bool Transparent = {read=GetTransparent, write=SetTransparent, nodefault};
	__property Byte TransparentColorIndex = {read=GetTransparentColorIndex, write=SetTransparentColorIndex, nodefault};
	__property Graphics::TColor TransparentColor = {read=GetTransparentColor, write=SetTransparentColor, nodefault};
	__property bool UserInput = {read=GetUserInput, write=SetUserInput, nodefault};
	__property TDisposalMethod Disposal = {read=GetDisposal, write=SetDisposal, nodefault};
};


class PASCALIMPLEMENTATION TGIFSubImage : public TGIFItem 
{
	typedef TGIFItem inherited;
	
private:
	Graphics::TBitmap* FBitmap;
	HBITMAP FMask;
	bool FNeedMask;
	HPALETTE FLocalPalette;
	char *FData;
	int FDataSize;
	TGIFColorMap* FColorMap;
	#pragma pack(push, 1)
	TImageDescriptor FImageDescriptor;
	#pragma pack(pop)
	
	TGIFExtensionList* FExtensions;
	bool FTransparent;
	TGIFGraphicControlExtension* FGCE;
	void __fastcall Prepare(void);
	void __fastcall Compress(Classes::TStream* Stream);
	void __fastcall Decompress(Classes::TStream* Stream);
	
protected:
	virtual TGIFVersion __fastcall GetVersion(void);
	bool __fastcall GetInterlaced(void);
	void __fastcall SetInterlaced(bool Value);
	int __fastcall GetColorResolution(void);
	int __fastcall GetBitsPerPixel(void);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	Graphics::TBitmap* __fastcall DoGetBitmap(void);
	Graphics::TBitmap* __fastcall DoGetDitherBitmap(void);
	Graphics::TBitmap* __fastcall GetBitmap(void);
	void __fastcall SetBitmap(Graphics::TBitmap* Value);
	void __fastcall FreeMask(void);
	bool __fastcall GetEmpty(void);
	HPALETTE __fastcall GetPalette(void);
	void __fastcall SetPalette(HPALETTE Value);
	TGIFColorMap* __fastcall GetActiveColorMap(void);
	Types::TRect __fastcall GetBoundsRect();
	void __fastcall SetBoundsRect(const Types::TRect &Value);
	void __fastcall DoSetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	Types::TRect __fastcall GetClientRect();
	Byte __fastcall GetPixel(int x, int y);
	void __fastcall SetPixel(int x, int y, Byte Value);
	void * __fastcall GetScanline(int y);
	void __fastcall NewBitmap(void);
	void __fastcall FreeBitmap(void);
	void __fastcall NewImage(void);
	void __fastcall FreeImage(void);
	void __fastcall NeedImage(void);
	Types::TRect __fastcall ScaleRect(const Types::TRect &DestRect);
	bool __fastcall HasMask(void);
	Word __fastcall GetBounds(int Index);
	void __fastcall SetBounds(int Index, Word Value);
	bool __fastcall GetHasBitmap(void);
	void __fastcall SetHasBitmap(bool Value);
	
public:
	__fastcall virtual TGIFSubImage(TGIFImage* GIFImage);
	__fastcall virtual ~TGIFSubImage(void);
	void __fastcall Clear(void);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Draw(Graphics::TCanvas* ACanvas, const Types::TRect &Rect, bool DoTransparent, bool DoTile);
	void __fastcall StretchDraw(Graphics::TCanvas* ACanvas, const Types::TRect &Rect, bool DoTransparent, bool DoTile);
	void __fastcall Crop(void);
	void __fastcall Merge(TGIFSubImage* Previous);
	__property bool HasBitmap = {read=GetHasBitmap, write=SetHasBitmap, nodefault};
	__property Word Left = {read=GetBounds, write=SetBounds, index=1, nodefault};
	__property Word Top = {read=GetBounds, write=SetBounds, index=2, nodefault};
	__property Word Width = {read=GetBounds, write=SetBounds, index=3, nodefault};
	__property Word Height = {read=GetBounds, write=SetBounds, index=4, nodefault};
	__property Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property Types::TRect ClientRect = {read=GetClientRect};
	__property bool Interlaced = {read=GetInterlaced, write=SetInterlaced, nodefault};
	__property TGIFColorMap* ColorMap = {read=FColorMap};
	__property TGIFColorMap* ActiveColorMap = {read=GetActiveColorMap};
	__property char * Data = {read=FData};
	__property int DataSize = {read=FDataSize, nodefault};
	__property TGIFExtensionList* Extensions = {read=FExtensions};
	__property TGIFVersion Version = {read=GetVersion, nodefault};
	__property int ColorResolution = {read=GetColorResolution, nodefault};
	__property int BitsPerPixel = {read=GetBitsPerPixel, nodefault};
	__property Graphics::TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap};
	__property HBITMAP Mask = {read=FMask, nodefault};
	__property HPALETTE Palette = {read=GetPalette, write=SetPalette, nodefault};
	__property bool Empty = {read=GetEmpty, nodefault};
	__property bool Transparent = {read=FTransparent, nodefault};
	__property TGIFGraphicControlExtension* GraphicControlExtension = {read=FGCE};
	__property Byte Pixels[int x][int y] = {read=GetPixel, write=SetPixel};
	__property void * Scanline[int y] = {read=GetScanline};
};


class DELPHICLASS TGIFTrailer;
class PASCALIMPLEMENTATION TGIFTrailer : public TGIFItem 
{
	typedef TGIFItem inherited;
	
__published:
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TGIFItem.Create */ inline __fastcall virtual TGIFTrailer(TGIFImage* GIFImage) : TGIFItem(GIFImage) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGIFTrailer(void) { }
	#pragma option pop
	
};


#pragma pack(push, 1)
struct TGIFPlainTextExtensionRec
{
	Byte BlockSize;
	Word Left;
	Word Top;
	Word Width;
	Word Height;
	Byte CellWidth;
	Byte CellHeight;
	Byte TextFGColorIndex;
	Byte TextBGColorIndex;
} ;
#pragma pack(pop)

class DELPHICLASS TGIFTextExtension;
class PASCALIMPLEMENTATION TGIFTextExtension : public TGIFExtension 
{
	typedef TGIFExtension inherited;
	
private:
	Classes::TStrings* FText;
	#pragma pack(push, 1)
	TGIFPlainTextExtensionRec FPlainTextExtension;
	#pragma pack(pop)
	
	
protected:
	virtual Byte __fastcall GetExtensionType(void);
	Graphics::TColor __fastcall GetForegroundColor(void);
	void __fastcall SetForegroundColor(Graphics::TColor Color);
	Graphics::TColor __fastcall GetBackgroundColor(void);
	void __fastcall SetBackgroundColor(Graphics::TColor Color);
	Word __fastcall GetBounds(int Index);
	void __fastcall SetBounds(int Index, Word Value);
	Byte __fastcall GetCharWidthHeight(int Index);
	void __fastcall SetCharWidthHeight(int Index, Byte Value);
	Byte __fastcall GetColorIndex(int Index);
	void __fastcall SetColorIndex(int Index, Byte Value);
	
public:
	__fastcall virtual TGIFTextExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFTextExtension(void);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	__property Word Left = {read=GetBounds, write=SetBounds, index=1, nodefault};
	__property Word Top = {read=GetBounds, write=SetBounds, index=2, nodefault};
	__property Word GridWidth = {read=GetBounds, write=SetBounds, index=3, nodefault};
	__property Word GridHeight = {read=GetBounds, write=SetBounds, index=4, nodefault};
	__property Byte CharWidth = {read=GetCharWidthHeight, write=SetCharWidthHeight, index=1, nodefault};
	__property Byte CharHeight = {read=GetCharWidthHeight, write=SetCharWidthHeight, index=2, nodefault};
	__property Byte ForegroundColorIndex = {read=GetColorIndex, write=SetColorIndex, index=1, nodefault};
	__property Graphics::TColor ForegroundColor = {read=GetForegroundColor, nodefault};
	__property Byte BackgroundColorIndex = {read=GetColorIndex, write=SetColorIndex, index=2, nodefault};
	__property Graphics::TColor BackgroundColor = {read=GetBackgroundColor, nodefault};
	__property Classes::TStrings* Text = {read=FText, write=FText};
};


class DELPHICLASS TGIFCommentExtension;
class PASCALIMPLEMENTATION TGIFCommentExtension : public TGIFExtension 
{
	typedef TGIFExtension inherited;
	
private:
	Classes::TStrings* FText;
	
protected:
	virtual Byte __fastcall GetExtensionType(void);
	
public:
	__fastcall virtual TGIFCommentExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFCommentExtension(void);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	__property Classes::TStrings* Text = {read=FText};
};


typedef char TGIFIdentifierCode[8];

typedef char TGIFAuthenticationCode[3];

#pragma pack(push, 1)
struct TGIFApplicationRec
{
	char Identifier[8];
	char Authentication[3];
} ;
#pragma pack(pop)

typedef TMetaClass*TGIFAppExtensionClass;

class DELPHICLASS TGIFApplicationExtension;
class PASCALIMPLEMENTATION TGIFApplicationExtension : public TGIFExtension 
{
	typedef TGIFExtension inherited;
	
private:
	#pragma pack(push, 1)
	TGIFApplicationRec FIdent;
	#pragma pack(pop)
	
	AnsiString __fastcall GetAuthentication();
	AnsiString __fastcall GetIdentifier();
	
protected:
	virtual Byte __fastcall GetExtensionType(void);
	void __fastcall SetAuthentication(const AnsiString Value);
	void __fastcall SetIdentifier(const AnsiString Value);
	virtual void __fastcall SaveData(Classes::TStream* Stream) = 0 ;
	virtual void __fastcall LoadData(Classes::TStream* Stream) = 0 ;
	
public:
	__fastcall virtual TGIFApplicationExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFApplicationExtension(void);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	/*         class method */ static void __fastcall RegisterExtension(TMetaClass* vmt, const TGIFApplicationRec &eIdent, TMetaClass* eClass);
	/* virtual class method */ virtual TMetaClass* __fastcall FindSubExtension(TMetaClass* vmt, Classes::TStream* Stream);
	__property AnsiString Identifier = {read=GetIdentifier, write=SetIdentifier};
	__property AnsiString Authentication = {read=GetAuthentication, write=SetAuthentication};
};


class DELPHICLASS TGIFBlock;
class PASCALIMPLEMENTATION TGIFBlock : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Byte FSize;
	void *FData;
	
public:
	__fastcall TGIFBlock(int ASize);
	__fastcall virtual ~TGIFBlock(void);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	__property Byte Size = {read=FSize, nodefault};
	__property void * Data = {read=FData};
};


class DELPHICLASS TGIFUnknownAppExtension;
class PASCALIMPLEMENTATION TGIFUnknownAppExtension : public TGIFApplicationExtension 
{
	typedef TGIFApplicationExtension inherited;
	
private:
	Classes::TList* FBlocks;
	
protected:
	virtual void __fastcall SaveData(Classes::TStream* Stream);
	virtual void __fastcall LoadData(Classes::TStream* Stream);
	
public:
	__fastcall virtual TGIFUnknownAppExtension(TGIFSubImage* ASubImage);
	__fastcall virtual ~TGIFUnknownAppExtension(void);
	__property Classes::TList* Blocks = {read=FBlocks};
};


class DELPHICLASS TGIFAppExtNSLoop;
class PASCALIMPLEMENTATION TGIFAppExtNSLoop : public TGIFApplicationExtension 
{
	typedef TGIFApplicationExtension inherited;
	
private:
	Word FLoops;
	unsigned FBufferSize;
	
protected:
	virtual void __fastcall SaveData(Classes::TStream* Stream);
	virtual void __fastcall LoadData(Classes::TStream* Stream);
	
public:
	__fastcall virtual TGIFAppExtNSLoop(TGIFSubImage* ASubImage);
	__property Word Loops = {read=FLoops, write=FLoops, nodefault};
	__property unsigned BufferSize = {read=FBufferSize, write=FBufferSize, nodefault};
public:
	#pragma option push -w-inl
	/* TGIFApplicationExtension.Destroy */ inline __fastcall virtual ~TGIFAppExtNSLoop(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word GIFVersion = 0x202;
static const Shortint GIFVersionMajor = 0x2;
static const Shortint GIFVersionMinor = 0x2;
static const Shortint GIFVersionRelease = 0x5;
static const Word GIFMaxColors = 0x100;
static const int BitmapAllocationThreshold = 0x7a120;
extern PACKAGE int GIFDelayExp;
extern PACKAGE int GIFDefaultDelay;
extern PACKAGE int GIFMinimumDelay;
extern PACKAGE int GIFMaximumDelay;
extern PACKAGE char GIFVersions[2][3];
extern PACKAGE Word CF_GIF;
extern PACKAGE TGIFDrawOptions GIFImageDefaultDrawOptions;
extern PACKAGE TColorReduction GIFImageDefaultColorReduction;
extern PACKAGE int GIFImageDefaultColorReductionBits;
extern PACKAGE TDitherMode GIFImageDefaultDitherMode;
extern PACKAGE TGIFCompression GIFImageDefaultCompression;
extern PACKAGE Classes::TThreadPriority GIFImageDefaultThreadPriority;
extern PACKAGE int GIFImageDefaultAnimationSpeed;
extern PACKAGE bool DoAutoDither;
extern PACKAGE bool PaletteDevice;
extern PACKAGE bool GIFImageRenderOnLoad;
extern PACKAGE bool GIFImageOptimizeOnStream;
extern PACKAGE System::ResourceString _sOutOfData;
#define Gifimage_sOutOfData System::LoadResourceString(&Gifimage::_sOutOfData)
extern PACKAGE System::ResourceString _sTooManyColors;
#define Gifimage_sTooManyColors System::LoadResourceString(&Gifimage::_sTooManyColors)
extern PACKAGE System::ResourceString _sBadColorIndex;
#define Gifimage_sBadColorIndex System::LoadResourceString(&Gifimage::_sBadColorIndex)
extern PACKAGE System::ResourceString _sBadVersion;
#define Gifimage_sBadVersion System::LoadResourceString(&Gifimage::_sBadVersion)
extern PACKAGE System::ResourceString _sBadSignature;
#define Gifimage_sBadSignature System::LoadResourceString(&Gifimage::_sBadSignature)
extern PACKAGE System::ResourceString _sScreenBadColorSize;
#define Gifimage_sScreenBadColorSize System::LoadResourceString(&Gifimage::_sScreenBadColorSize)
extern PACKAGE System::ResourceString _sImageBadColorSize;
#define Gifimage_sImageBadColorSize System::LoadResourceString(&Gifimage::_sImageBadColorSize)
extern PACKAGE System::ResourceString _sUnknownExtension;
#define Gifimage_sUnknownExtension System::LoadResourceString(&Gifimage::_sUnknownExtension)
extern PACKAGE System::ResourceString _sBadExtensionLabel;
#define Gifimage_sBadExtensionLabel System::LoadResourceString(&Gifimage::_sBadExtensionLabel)
extern PACKAGE System::ResourceString _sOutOfMemDIB;
#define Gifimage_sOutOfMemDIB System::LoadResourceString(&Gifimage::_sOutOfMemDIB)
extern PACKAGE System::ResourceString _sDIBCreate;
#define Gifimage_sDIBCreate System::LoadResourceString(&Gifimage::_sDIBCreate)
extern PACKAGE System::ResourceString _sDecodeTooFewBits;
#define Gifimage_sDecodeTooFewBits System::LoadResourceString(&Gifimage::_sDecodeTooFewBits)
extern PACKAGE System::ResourceString _sDecodeCircular;
#define Gifimage_sDecodeCircular System::LoadResourceString(&Gifimage::_sDecodeCircular)
extern PACKAGE System::ResourceString _sBadTrailer;
#define Gifimage_sBadTrailer System::LoadResourceString(&Gifimage::_sBadTrailer)
extern PACKAGE System::ResourceString _sBadExtensionInstance;
#define Gifimage_sBadExtensionInstance System::LoadResourceString(&Gifimage::_sBadExtensionInstance)
extern PACKAGE System::ResourceString _sBadBlockSize;
#define Gifimage_sBadBlockSize System::LoadResourceString(&Gifimage::_sBadBlockSize)
extern PACKAGE System::ResourceString _sBadBlock;
#define Gifimage_sBadBlock System::LoadResourceString(&Gifimage::_sBadBlock)
extern PACKAGE System::ResourceString _sUnsupportedClass;
#define Gifimage_sUnsupportedClass System::LoadResourceString(&Gifimage::_sUnsupportedClass)
extern PACKAGE System::ResourceString _sInvalidData;
#define Gifimage_sInvalidData System::LoadResourceString(&Gifimage::_sInvalidData)
extern PACKAGE System::ResourceString _sBadHeight;
#define Gifimage_sBadHeight System::LoadResourceString(&Gifimage::_sBadHeight)
extern PACKAGE System::ResourceString _sBadWidth;
#define Gifimage_sBadWidth System::LoadResourceString(&Gifimage::_sBadWidth)
extern PACKAGE System::ResourceString _sFailedPaste;
#define Gifimage_sFailedPaste System::LoadResourceString(&Gifimage::_sFailedPaste)
extern PACKAGE System::ResourceString _sScreenSizeExceeded;
#define Gifimage_sScreenSizeExceeded System::LoadResourceString(&Gifimage::_sScreenSizeExceeded)
extern PACKAGE System::ResourceString _sNoColorTable;
#define Gifimage_sNoColorTable System::LoadResourceString(&Gifimage::_sNoColorTable)
extern PACKAGE System::ResourceString _sBadPixelCoordinates;
#define Gifimage_sBadPixelCoordinates System::LoadResourceString(&Gifimage::_sBadPixelCoordinates)
extern PACKAGE System::ResourceString _sUnsupportedBitmap;
#define Gifimage_sUnsupportedBitmap System::LoadResourceString(&Gifimage::_sUnsupportedBitmap)
extern PACKAGE System::ResourceString _sInvalidPixelFormat;
#define Gifimage_sInvalidPixelFormat System::LoadResourceString(&Gifimage::_sInvalidPixelFormat)
extern PACKAGE System::ResourceString _sBadDimension;
#define Gifimage_sBadDimension System::LoadResourceString(&Gifimage::_sBadDimension)
extern PACKAGE System::ResourceString _sNoDIB;
#define Gifimage_sNoDIB System::LoadResourceString(&Gifimage::_sNoDIB)
extern PACKAGE System::ResourceString _sInvalidStream;
#define Gifimage_sInvalidStream System::LoadResourceString(&Gifimage::_sInvalidStream)
extern PACKAGE System::ResourceString _sInvalidColor;
#define Gifimage_sInvalidColor System::LoadResourceString(&Gifimage::_sInvalidColor)
extern PACKAGE System::ResourceString _sInvalidBitSize;
#define Gifimage_sInvalidBitSize System::LoadResourceString(&Gifimage::_sInvalidBitSize)
extern PACKAGE System::ResourceString _sEmptyColorMap;
#define Gifimage_sEmptyColorMap System::LoadResourceString(&Gifimage::_sEmptyColorMap)
extern PACKAGE System::ResourceString _sEmptyImage;
#define Gifimage_sEmptyImage System::LoadResourceString(&Gifimage::_sEmptyImage)
extern PACKAGE System::ResourceString _sInvalidBitmapList;
#define Gifimage_sInvalidBitmapList System::LoadResourceString(&Gifimage::_sInvalidBitmapList)
extern PACKAGE System::ResourceString _sInvalidReduction;
#define Gifimage_sInvalidReduction System::LoadResourceString(&Gifimage::_sInvalidReduction)
extern PACKAGE System::ResourceString _sGIFImageFile;
#define Gifimage_sGIFImageFile System::LoadResourceString(&Gifimage::_sGIFImageFile)
extern PACKAGE System::ResourceString _sProgressLoading;
#define Gifimage_sProgressLoading System::LoadResourceString(&Gifimage::_sProgressLoading)
extern PACKAGE System::ResourceString _sProgressSaving;
#define Gifimage_sProgressSaving System::LoadResourceString(&Gifimage::_sProgressSaving)
extern PACKAGE System::ResourceString _sProgressConverting;
#define Gifimage_sProgressConverting System::LoadResourceString(&Gifimage::_sProgressConverting)
extern PACKAGE System::ResourceString _sProgressRendering;
#define Gifimage_sProgressRendering System::LoadResourceString(&Gifimage::_sProgressRendering)
extern PACKAGE System::ResourceString _sProgressCopying;
#define Gifimage_sProgressCopying System::LoadResourceString(&Gifimage::_sProgressCopying)
extern PACKAGE System::ResourceString _sProgressOptimizing;
#define Gifimage_sProgressOptimizing System::LoadResourceString(&Gifimage::_sProgressOptimizing)
extern PACKAGE void __fastcall Register(void);
extern PACKAGE HPALETTE __fastcall WebPalette(void);
extern PACKAGE void __fastcall InternalGetDIBSizes(HBITMAP Bitmap, int &InfoHeaderSize, int &ImageSize, Graphics::TPixelFormat PixelFormat);
extern PACKAGE bool __fastcall InternalGetDIB(HBITMAP Bitmap, HPALETTE Palette, void *BitmapInfo, void *Bits, Graphics::TPixelFormat PixelFormat);
extern PACKAGE HPALETTE __fastcall CreateOptimizedPaletteFromManyBitmaps(Classes::TList* Bitmaps, int Colors, int ColorBits, bool Windows);
extern PACKAGE Graphics::TBitmap* __fastcall ReduceColors(Graphics::TBitmap* Bitmap, TColorReduction ColorReduction, TDitherMode DitherMode, int ReductionBits, HPALETTE CustomPalette);

}	/* namespace Gifimage */
using namespace Gifimage;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GIFImage
