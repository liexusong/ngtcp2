/*
 * ngtcp2
 *
 * Copyright (c) 2017 ngtcp2 contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef CLIENT_H
#define CLIENT_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif // HAVE_CONFIG_H

#include <vector>

#include <ngtcp2/ngtcp2.h>

#include <openssl/ssl.h>

#include <ev.h>

#include "network.h"

using namespace ngtcp2;

class Client {
public:
  Client(struct ev_loop *loop, SSL_CTX *ssl_ctx);
  ~Client();

  int init(int fd, const Address &remote_addr);
  void disconnect();

  int tls_handshake();
  int on_read();
  int on_write();
  int feed_data(const uint8_t *data, size_t datalen);

  void write_client_handshake(const uint8_t *data, size_t datalen);
  size_t read_client_handshake(const uint8_t **pdest);

  size_t read_server_handshake(uint8_t *buf, size_t buflen);
  void write_server_handshake(const uint8_t *data, size_t datalen);

private:
  Address remote_addr_;
  size_t max_pktlen_;
  ev_io wev_;
  ev_io rev_;
  struct ev_loop *loop_;
  SSL_CTX *ssl_ctx_;
  SSL *ssl_;
  int fd_;
  std::vector<uint8_t> chandshake_;
  size_t ncread_;
  std::vector<uint8_t> shandshake_;
  size_t nsread_;
  ngtcp2_conn *conn_;
};

#endif // CLIENT_H
