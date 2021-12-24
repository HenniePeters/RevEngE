object frmPref: TfrmPref
  Left = 668
  Top = 624
  BorderStyle = bsToolWindow
  Caption = ' Preferences'
  ClientHeight = 287
  ClientWidth = 419
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 11
    Top = 16
    Width = 3
    Height = 13
  end
  object cmdOK: TButton
    Left = 112
    Top = 248
    Width = 97
    Height = 25
    Caption = 'OK'
    Default = True
    TabOrder = 0
    OnClick = cmdOKClick
  end
  object cmdCancel: TButton
    Left = 216
    Top = 248
    Width = 89
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = cmdCancelClick
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 104
    Width = 401
    Height = 57
    Caption = 'Show images:'
    TabOrder = 2
    object chkStretched: TRadioButton
      Left = 120
      Top = 24
      Width = 73
      Height = 17
      Caption = 'Stretched'
      TabOrder = 0
    end
    object chkProportional: TRadioButton
      Left = 16
      Top = 24
      Width = 81
      Height = 17
      Caption = 'Proportional'
      TabOrder = 1
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 176
    Width = 401
    Height = 57
    Caption = 'Mirror image:'
    TabOrder = 3
    object chkMirror1: TRadioButton
      Tag = 1
      Left = 16
      Top = 24
      Width = 57
      Height = 17
      Caption = 'Image1'
      TabOrder = 0
      OnClick = chkMirror1Click
    end
    object chkMirror2: TRadioButton
      Tag = 2
      Left = 120
      Top = 24
      Width = 65
      Height = 17
      Caption = 'Image2'
      TabOrder = 1
      OnClick = chkMirror2Click
    end
    object chkMirrorNone: TRadioButton
      Left = 224
      Top = 24
      Width = 57
      Height = 17
      Caption = 'None'
      TabOrder = 2
      OnClick = chkMirrorNoneClick
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 8
    Width = 401
    Height = 81
    Caption = 'Startup gradient:'
    TabOrder = 4
    object Label2: TLabel
      Left = 16
      Top = 54
      Width = 35
      Height = 13
      Caption = 'Image1'
    end
    object Label3: TLabel
      Left = 350
      Top = 54
      Width = 35
      Height = 13
      Caption = 'Image2'
    end
    object trbGradient: TTrackBar
      Left = 8
      Top = 21
      Width = 385
      Height = 33
      Max = 5
      Orientation = trHorizontal
      Frequency = 1
      Position = 5
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBottomRight
      TickStyle = tsAuto
    end
  end
end
