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

## DYA Studio での接続

ブラウザ上でキーマップやトラックボール感度を編集できる [DYA Studio](https://studio.dya.cormoran.works/) に対応しています。

### 接続手順

1. **右手側（central）** を USB ケーブルで PC に直結する
2. Chrome / Edge / Arc など [Web Serial API](https://developer.mozilla.org/docs/Web/API/Web_Serial_API) 対応ブラウザで <https://studio.dya.cormoran.works/> を開く（Firefox / Safari は非対応）
3. 「接続」→ シリアルポート一覧から右手側を選択
4. `&studio_unlock` キーを押してロック解除（下記参照）
5. キーマップ編集 / トラックボール感度調整 / バッテリー履歴確認 → 保存で右手側に書き込み

### unlock キーの位置

`&studio_unlock` は **layer6 の左手最上段・左端**（layer0 で `Q` がある物理位置）に配置されています。

操作手順:

1. layer0 で **左手親指クラスタ左から 2 番目のキー（`lt 6 ESCAPE`）を長押し** → layer6 に入る
2. その状態で **左手最上段の左端キー** を押す → ロック解除

## 参考

- [cool642tb-mini 使い方ガイド](https://note.com/na__ka__no/n/n6d4a7c7ecf30)
- [cool642tb-mini - BOOTH](https://nakanoo.booth.pm/items/7464429)
- [ZMK Firmware](https://zmk.dev/)
- [na-ka-no/zmk](https://github.com/na-ka-no/zmk) - PMW3610対応フォーク
- [zmk-pmw3610-driver](https://github.com/na-ka-no/zmk-pmw3610-driver)
