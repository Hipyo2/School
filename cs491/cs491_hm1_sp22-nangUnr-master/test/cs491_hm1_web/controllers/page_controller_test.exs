defmodule Cs491Hm1Web.PageControllerTest do
  use Cs491Hm1Web.ConnCase

  test "GET /", %{conn: conn} do
    conn = get(conn, "/")
    assert html_response(conn, 200) =~ "Welcome to Phoenix!"
  end
end
