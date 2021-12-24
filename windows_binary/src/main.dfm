object frmMain: TfrmMain
  Left = 329
  Top = 121
  Width = 749
  Height = 490
  Caption = ' RevEngE'
  Color = clBtnFace
  Constraints.MinHeight = 100
  Constraints.MinWidth = 100
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF006666
    6766444444444466678877776666666667774444444444466667777666646666
    6667764446444444666466666644666666667764444444444666666664446666
    6666677446444444444444444444666666666677444444444444444444446666
    6666666774444444444444444444466666666666776444444444444444444444
    6666666667764444444444444444444446666666667774444444444444444444
    4466666666677777777644444444444444466666666677777777764444444444
    4444466666666666666677744444644444444466666666666666678744446644
    6444446666666666666646776444664464444446666666644446646774444444
    4444444466664400004466677444444444444444666644000004666676444464
    4444444664664000000466667644446644444444447640000004666666446446
    644444446687400000046666644474466444444444786000004666666444F746
    6444444444688600444666664444F7466644444446468877776666664444F744
    6644444446646777776666644444776466664444444666666666666444447646
    4644444444446666666664444444666464444444444446666664444444446666
    6444444444444444444444444444466644444444444444444444444444446444
    4444444444444444444444444444764444444444444444444444444444440000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000}
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnMouseWheel = FormMouseWheel
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 741
    Height = 425
    Align = alClient
    Proportional = True
    Visible = False
  end
  object Image2: TImage
    Left = 0
    Top = 0
    Width = 741
    Height = 425
    Align = alClient
    Proportional = True
    Visible = False
  end
  object Image3: TImage
    Left = 0
    Top = 0
    Width = 741
    Height = 425
    Align = alClient
    Proportional = True
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 425
    Width = 741
    Height = 19
    Panels = <
      item
        Width = 200
      end
      item
        Width = 200
      end
      item
        Width = 0
      end>
    SimplePanel = False
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 8
    object mnuFile: TMenuItem
      Caption = '&File'
      object mnuLoadImage1: TMenuItem
        Caption = 'Load image&1'
        OnClick = mnuLoadImage1Click
      end
      object mnuLoadImage2: TMenuItem
        Caption = 'Load image&2'
        OnClick = mnuLoadImage2Click
      end
      object mnuLatest: TMenuItem
        Caption = 'Load recent files'
        OnClick = mnuLatestClick
      end
      object mnuPreferences: TMenuItem
        Caption = '&Preferences'
        OnClick = mnuPreferencesClick
      end
      object mnuExit: TMenuItem
        Caption = 'E&xit'
        OnClick = mnuExitClick
      end
    end
    object mnuHelp: TMenuItem
      Caption = '&Help'
      object mnuAboutRevEngE: TMenuItem
        Caption = '&About RevEngE'
        OnClick = mnuAboutRevEngEClick
      end
      object mnuHowTo: TMenuItem
        Caption = 'How to use'
        OnClick = mnuHowToClick
      end
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Filter = 
      'All supported image files(*.jpg;*.jpeg;*.bmp;*.gif)|*.jpg;*.jpeg' +
      ';*.bmp;*.gif|JPEG Image file (*.jpg)|*.jpg|JPEG Image file (*.jp' +
      'eg)|*.jpeg|Bitmaps (*.bmp)|*.bmp|GIF Image file (*.gif)|*.gif'
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofEnableSizing]
    Left = 48
    Top = 8
  end
end
