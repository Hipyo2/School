defmodule Cs491Hm1Web.PageController do
  use Cs491Hm1Web, :controller

  def index(conn, _params) do
    render(conn, "index.html")
  end
end
