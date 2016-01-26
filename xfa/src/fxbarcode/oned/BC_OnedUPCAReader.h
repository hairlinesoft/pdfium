// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef _BC_ONEDUPCAREADER_H_
#define _BC_ONEDUPCAREADER_H_
class CBC_BinaryBitmap;
class CBC_CommonBitArray;
class CBC_OneDimReader;
class CBC_OnedEAN13Reader;
class CBC_OnedUPCAReader;
class CBC_OnedUPCAReader : public CBC_OneDimReader {
 private:
  CBC_OnedEAN13Reader* m_ean13Reader;

 public:
  CBC_OnedUPCAReader();
  virtual ~CBC_OnedUPCAReader();
  CFX_ByteString DecodeRow(int32_t rowNumber,
                           CBC_CommonBitArray* row,
                           int32_t hints,
                           int32_t& e);
  CFX_ByteString DecodeRow(int32_t rowNumber,
                           CBC_CommonBitArray* row,
                           CFX_Int32Array* startGuardRange,
                           int32_t hints,
                           int32_t& e);
  CFX_ByteString Decode(CBC_BinaryBitmap* image, int32_t& e);
  CFX_ByteString Decode(CBC_BinaryBitmap* image, int32_t hints, int32_t& e);
  virtual void Init();

 protected:
  int32_t DecodeMiddle(CBC_CommonBitArray* row,
                       CFX_Int32Array* startRange,
                       CFX_ByteString& resultString,
                       int32_t& e);
  CFX_ByteString MaybeReturnResult(CFX_ByteString& result, int32_t& e);
};
#endif
