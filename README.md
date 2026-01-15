# cool642tb-mini ZMK Firmware

cool642tb-mini 分割キーボード用のZMKファームウェア設定リポジトリです。

## 謝辞

このリポジトリは [na-ka-no/zmk-config-cool642tb-mini](https://github.com/na-ka-no/zmk-config-cool642tb-mini) をforkして作成しました。
オリジナルのキーボード設計およびファームウェアを公開してくださった [na-ka-no](https://github.com/na-ka-no) 様に感謝いたします。

## 概要

- **マイコン**: Seeeduino XIAO BLE
- **トラックボール**: PMW3610（右手側）
- **接続**: Bluetooth (BLE)
- **日本語配列**: JIS配列対応

## ビルド

GitHub Actionsにより自動ビルドされます。`main`ブランチへのpushまたはPull Requestで実行されます。

ビルド成果物:
- `cool642tb-mini_L-seeeduino_xiao_ble-zmk.uf2` - 左手側
- `cool642tb-mini_R-seeeduino_xiao_ble-zmk.uf2` - 右手側（トラックボール付き）
- `settings_reset-seeeduino_xiao_ble-zmk.uf2` - Bluetooth設定リセット用

## レイヤー構成

| レイヤー | 説明 |
|----------|------|
| layer0 | DEFAULT - 基本QWERTY配列 |
| layer1 | FUNCTION - 記号キー（JIS配列対応） |
| layer2 | NUM - 数字・ファンクションキー |
| layer3 | ARROW - 矢印・ナビゲーション |
| layer4 | MOUSE - マウス操作 |
| layer5 | SCROLL - スクロール操作 |
| layer6 | BLUETOOTH - BT接続管理 |

## ファイル構成

```
config/
├── cool642tb-mini.keymap    # キーマップ定義
├── cool642tb-mini.json      # レイアウト定義
├── locale/
│   └── keys_ja.h            # 日本語(JIS)キー定義
├── boards/shields/Test/     # シールド設定
│   ├── cool642tb-mini.dtsi
│   ├── cool642tb-mini_L.conf
│   ├── cool642tb-mini_L.overlay
│   ├── cool642tb-mini_R.conf
│   └── cool642tb-mini_R.overlay
└── west.yml                 # 依存関係定義
```

## ファームウェア書き込み

1. Seeeduino XIAO BLEをブートローダーモードにする（リセットボタン2回押し）
2. マウントされたドライブに`.uf2`ファイルをコピー
3. 自動的に再起動してファームウェアが適用される

## 参考

- [ZMK Firmware](https://zmk.dev/)
- [na-ka-no/zmk](https://github.com/na-ka-no/zmk) - PMW3610対応フォーク
- [zmk-pmw3610-driver](https://github.com/na-ka-no/zmk-pmw3610-driver)
