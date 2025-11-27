# DDS Pub/Sub Örneği (C++ / Fast DDS)

Bu proje, **eProsima Fast DDS** kullanarak C++ ile basit bir Publisher ve Subscriber uygulaması örneğidir. IDL dosyası kullanılmadan, doğrudan struct ile veri alışverişi yapılmaktadır.  

Publisher sürekli veri gönderir ve Subscriber bunu alır.

---

## Gereksinimler

- C++17 uyumlu derleyici (MSVC, GCC veya Clang)
- [vcpkg](https://github.com/microsoft/vcpkg) paket yöneticisi
- Windows için Visual Studio 2022 önerilir

---

## Kurulum Adımları

### 1. vcpkg'yi indirin ve kurun

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
```

vcpkg kurulu olduğu yolu ortam değişkenlerine ekleyin `.../vcpkg`

```bash
vcpkg integrate install
vcpkg install fastdds
```

Ardından `.../vcpkg/installed/x64-windows/lib` içeriğine gidip `fastdds-3.3.lib` dosyasını silmeden `vcpkg/installed/x64-windows/lib` klasörüne `libfastddsd-3.3.lib` // `libfastdds-3.3.lib` isimlerinde kopyalıyoruz.

Ardından aynı işlemi `.../vcpkg/installed/x64-windows/debug/lib` içeriğine gidip `fastddsd-3.3.lib` dosyasını silmeden `vcpkg/installed/x64-windows/debug/lib` klasörüne `libfastddsd-3.3.lib` // `libfastdds-3.3.lib` isimlerinde kopyalıyoruz.

vcpkg ile Visual Studio entegrasyonunda sıkıntı yok ise projeyi derleyebilirsiniz. 

Veri yapıları (MyType) IDL dosyası kullanmadan `.h` dosyası şeklinde tanımlanabilir.

---

# DDS Pub/Sub Example (C++ / Fast DDS)

This project is a simple Publisher and Subscriber application example using **eProsima Fast DDS** with C++. Data exchange is performed directly using structs without IDL files.

The Publisher continuously sends data and the Subscriber receives it.

---

## Requirements

- C++17 compatible compiler (MSVC, GCC or Clang)
- [vcpkg](https://github.com/microsoft/vcpkg) package manager
- Visual Studio 2022 recommended for Windows

---

## Installation Steps

### 1. Download and install vcpkg

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
```

Add the vcpkg installation path to environment variables `.../vcpkg`

```bash
vcpkg integrate install
vcpkg install fastdds
```

Then navigate to `.../vcpkg/installed/x64-windows/lib` and without deleting `fastdds-3.3.lib`, copy it to `vcpkg/installed/x64-windows/lib` folder with the names `libfastddsd-3.3.lib` // `libfastdds-3.3.lib`.

Then perform the same operation by navigating to `.../vcpkg/installed/x64-windows/debug/lib` and without deleting `fastddsd-3.3.lib`, copy it to `vcpkg/installed/x64-windows/debug/lib` folder with the names `libfastddsd-3.3.lib` // `libfastdds-3.3.lib`.

If there are no issues with vcpkg and Visual Studio integration, you can compile the project.

Data structures (MyType) can be defined as `.h` files without using IDL files.

---

# DDS Pub/Sub Beispiel (C++ / Fast DDS)

Dieses Projekt ist ein einfaches Publisher- und Subscriber-Anwendungsbeispiel mit **eProsima Fast DDS** in C++. Der Datenaustausch erfolgt direkt über Structs ohne IDL-Dateien.

Der Publisher sendet kontinuierlich Daten und der Subscriber empfängt sie.

---

## Anforderungen

- C++17-kompatibler Compiler (MSVC, GCC oder Clang)
- [vcpkg](https://github.com/microsoft/vcpkg) Paketmanager
- Visual Studio 2022 wird für Windows empfohlen

---

## Installationsschritte

### 1. vcpkg herunterladen und installieren

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
```

Fügen Sie den vcpkg-Installationspfad zu den Umgebungsvariablen hinzu `.../vcpkg`

```bash
vcpkg integrate install
vcpkg install fastdds
```

Navigieren Sie dann zu `.../vcpkg/installed/x64-windows/lib` und kopieren Sie `fastdds-3.3.lib`, ohne es zu löschen, in den Ordner `vcpkg/installed/x64-windows/lib` mit den Namen `libfastddsd-3.3.lib` // `libfastdds-3.3.lib`.

Führen Sie dann die gleiche Operation durch, indem Sie zu `.../vcpkg/installed/x64-windows/debug/lib` navigieren und `fastddsd-3.3.lib`, ohne es zu löschen, in den Ordner `vcpkg/installed/x64-windows/debug/lib` mit den Namen `libfastddsd-3.3.lib` // `libfastdds-3.3.lib` kopieren.

Wenn es keine Probleme mit der vcpkg- und Visual Studio-Integration gibt, können Sie das Projekt kompilieren.

Datenstrukturen (MyType) können als `.h`-Dateien ohne IDL-Dateien definiert werden.

---

# DDS Pub/Sub サンプル (C++ / Fast DDS)

このプロジェクトは、**eProsima Fast DDS**を使用したC++での簡単なPublisherとSubscriberアプリケーションの例です。IDLファイルを使用せず、構造体を直接使用してデータ交換を行います。

Publisherは継続的にデータを送信し、Subscriberがそれを受信します。

---

## 必要要件

- C++17互換コンパイラ(MSVC、GCC、またはClang)
- [vcpkg](https://github.com/microsoft/vcpkg)パッケージマネージャー
- Windows用にはVisual Studio 2022を推奨

---

## インストール手順

### 1. vcpkgのダウンロードとインストール

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
```

vcpkgインストールパスを環境変数に追加 `.../vcpkg`

```bash
vcpkg integrate install
vcpkg install fastdds
```

次に`.../vcpkg/installed/x64-windows/lib`に移動し、`fastdds-3.3.lib`を削除せずに、`vcpkg/installed/x64-windows/lib`フォルダに`libfastddsd-3.3.lib` // `libfastdds-3.3.lib`という名前でコピーします。

次に、同じ操作を`.../vcpkg/installed/x64-windows/debug/lib`に移動して行い、`fastddsd-3.3.lib`を削除せずに、`vcpkg/installed/x64-windows/debug/lib`フォルダに`libfastddsd-3.3.lib` // `libfastdds-3.3.lib`という名前でコピーします。

vcpkgとVisual Studioの統合に問題がなければ、プロジェクトをコンパイルできます。

データ構造(MyType)はIDLファイルを使用せず、`.h`ファイルとして定義できます。

---

# DDS 发布/订阅示例 (C++ / Fast DDS)

本项目是使用 **eProsima Fast DDS** 的 C++ 简单发布者和订阅者应用程序示例。无需使用 IDL 文件,直接通过结构体进行数据交换。

发布者持续发送数据,订阅者接收数据。

---

## 系统要求

- C++17 兼容编译器(MSVC、GCC 或 Clang)
- [vcpkg](https://github.com/microsoft/vcpkg) 包管理器
- Windows 系统推荐使用 Visual Studio 2022

---

## 安装步骤

### 1. 下载并安装 vcpkg

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
```

将 vcpkg 安装路径添加到环境变量 `.../vcpkg`

```bash
vcpkg integrate install
vcpkg install fastdds
```

然后导航到 `.../vcpkg/installed/x64-windows/lib`,在不删除 `fastdds-3.3.lib` 的情况下,将其复制到 `vcpkg/installed/x64-windows/lib` 文件夹,命名为 `libfastddsd-3.3.lib` // `libfastdds-3.3.lib`。

然后执行相同的操作,导航到 `.../vcpkg/installed/x64-windows/debug/lib`,在不删除 `fastddsd-3.3.lib` 的情况下,将其复制到 `vcpkg/installed/x64-windows/debug/lib` 文件夹,命名为 `libfastddsd-3.3.lib` // `libfastdds-3.3.lib`。

如果 vcpkg 与 Visual Studio 集成没有问题,即可编译项目。

数据结构(MyType)可以不使用 IDL 文件,直接定义为 `.h` 文件。