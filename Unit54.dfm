object Form1: TForm1
  Left = 42
  Top = 65
  Width = 1229
  Height = 828
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 24
    Top = 596
    Width = 23
    Height = 13
    Caption = 'Data'
  end
  object Label4: TLabel
    Left = 24
    Top = 648
    Width = 57
    Height = 16
    Caption = 'Status file'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 24
    Top = 628
    Width = 57
    Height = 16
    Caption = 'Name file'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 24
    Top = 668
    Width = 53
    Height = 16
    Caption = 'Have file'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 252
    Top = 736
    Width = 7
    Height = 13
    Caption = 'X'
  end
  object Label3: TLabel
    Left = 292
    Top = 736
    Width = 7
    Height = 13
    Caption = 'Y'
  end
  object Label7: TLabel
    Left = 336
    Top = 736
    Width = 7
    Height = 13
    Caption = 'Z'
  end
  object Label8: TLabel
    Left = 100
    Top = 740
    Width = 55
    Height = 13
    Caption = 'Start / Stop'
  end
  object Label9: TLabel
    Left = 500
    Top = 740
    Width = 25
    Height = 13
    Caption = 'LOW'
  end
  object Label10: TLabel
    Left = 396
    Top = 740
    Width = 27
    Height = 13
    Caption = 'HIGH'
  end
  object Memo1: TMemo
    Left = 20
    Top = 16
    Width = 221
    Height = 569
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Button1: TButton
    Left = 48
    Top = 700
    Width = 73
    Height = 29
    Caption = 'Connection'
    TabOrder = 1
    OnClick = Button1Click
  end
  object CheckBox1: TCheckBox
    Left = 72
    Top = 596
    Width = 17
    Height = 17
    Caption = 'CheckBox1'
    TabOrder = 2
  end
  object ComboBox1: TComboBox
    Left = 108
    Top = 596
    Width = 61
    Height = 21
    ItemHeight = 13
    TabOrder = 3
    Text = '1'
  end
  object Button2: TButton
    Left = 136
    Top = 700
    Width = 73
    Height = 29
    Caption = 'Save'
    TabOrder = 4
    OnClick = Button2Click
  end
  object ComboBox2: TComboBox
    Left = 180
    Top = 596
    Width = 61
    Height = 21
    ItemHeight = 13
    TabOrder = 5
    Text = '9600'
  end
  object Chart2: TChart
    Left = 248
    Top = 16
    Width = 949
    Height = 713
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'TChart')
    Title.Visible = False
    LeftAxis.ExactDateTime = False
    Legend.Visible = False
    View3D = False
    TabOrder = 6
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series2: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clGreen
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series3: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clBlue
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series4: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clYellow
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series5: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clWhite
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series6: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clGray
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object CheckBox2: TCheckBox
    Left = 268
    Top = 736
    Width = 17
    Height = 17
    Checked = True
    ParentShowHint = False
    ShowHint = False
    State = cbChecked
    TabOrder = 7
  end
  object CheckBox3: TCheckBox
    Left = 308
    Top = 736
    Width = 17
    Height = 17
    Checked = True
    State = cbChecked
    TabOrder = 8
  end
  object CheckBox4: TCheckBox
    Left = 352
    Top = 736
    Width = 17
    Height = 17
    Checked = True
    State = cbChecked
    TabOrder = 9
  end
  object Edit1: TEdit
    Left = 432
    Top = 736
    Width = 57
    Height = 21
    TabOrder = 10
    Text = '500'
  end
  object Edit2: TEdit
    Left = 536
    Top = 736
    Width = 57
    Height = 21
    TabOrder = 11
    Text = '500'
  end
  object MainMenu1: TMainMenu
    Left = 100
    Top = 628
    object File1: TMenuItem
      Caption = 'File'
      object CreateNew1: TMenuItem
        Caption = 'Create New'
        OnClick = CreateNew1Click
      end
      object Open1: TMenuItem
        Caption = 'Open'
        OnClick = Open1Click
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      OnClick = Help1Click
    end
  end
  object sOpenDialog1: TsOpenDialog
    Left = 132
    Top = 628
  end
  object sSaveDialog1: TsSaveDialog
    Left = 164
    Top = 628
  end
end
