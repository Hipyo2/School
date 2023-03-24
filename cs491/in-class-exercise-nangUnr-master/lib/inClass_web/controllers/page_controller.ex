defmodule InClassWeb.PageController do
  use InClassWeb, :controller

  def index(conn, _params) do
    render(conn, "index.html")
  end
end
