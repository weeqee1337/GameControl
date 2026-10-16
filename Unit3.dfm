object Form3: TForm3
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Password'
  ClientHeight = 123
  ClientWidth = 248
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  OnCloseQuery = FormCloseQuery
  TextHeight = 15
  object Label1: TLabel
    Left = -4
    Top = 8
    Width = 253
    Height = 30
    Alignment = taCenter
    AutoSize = False
    Caption = 'Password change'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Yu Gothic UI Semibold'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 15
    Top = 56
    Width = 163
    Height = 23
    TabStop = False
    MaxLength = 20
    ParentColor = True
    PasswordChar = '*'
    TabOrder = 0
    TextHint = 'Enter password...'
    OnChange = Edit1Change
  end
  object Button1: TButton
    Left = 15
    Top = 90
    Width = 131
    Height = 25
    Caption = 'Save password'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    TabStop = False
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 184
    Top = 55
    Width = 56
    Height = 25
    Caption = 'Show'
    TabOrder = 1
    TabStop = False
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 152
    Top = 90
    Width = 88
    Height = 25
    Caption = 'Cancel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    TabStop = False
    OnClick = Button3Click
  end
end
