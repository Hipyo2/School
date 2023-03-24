defmodule InClassWeb.DeveloperControllerTest do
  use InClassWeb.ConnCase

  import InClass.CompanyFixtures

  @create_attrs %{email: "some email", first_name: "some first_name", last_name: "some last_name"}
  @update_attrs %{email: "some updated email", first_name: "some updated first_name", last_name: "some updated last_name"}
  @invalid_attrs %{email: nil, first_name: nil, last_name: nil}

  describe "index" do
    test "lists all developers", %{conn: conn} do
      conn = get(conn, Routes.developer_path(conn, :index))
      assert html_response(conn, 200) =~ "Listing Developers"
    end
  end

  describe "new developer" do
    test "renders form", %{conn: conn} do
      conn = get(conn, Routes.developer_path(conn, :new))
      assert html_response(conn, 200) =~ "New Developer"
    end
  end

  describe "create developer" do
    test "redirects to show when data is valid", %{conn: conn} do
      conn = post(conn, Routes.developer_path(conn, :create), developer: @create_attrs)

      assert %{id: id} = redirected_params(conn)
      assert redirected_to(conn) == Routes.developer_path(conn, :show, id)

      conn = get(conn, Routes.developer_path(conn, :show, id))
      assert html_response(conn, 200) =~ "Show Developer"
    end

    test "renders errors when data is invalid", %{conn: conn} do
      conn = post(conn, Routes.developer_path(conn, :create), developer: @invalid_attrs)
      assert html_response(conn, 200) =~ "New Developer"
    end
  end

  describe "edit developer" do
    setup [:create_developer]

    test "renders form for editing chosen developer", %{conn: conn, developer: developer} do
      conn = get(conn, Routes.developer_path(conn, :edit, developer))
      assert html_response(conn, 200) =~ "Edit Developer"
    end
  end

  describe "update developer" do
    setup [:create_developer]

    test "redirects when data is valid", %{conn: conn, developer: developer} do
      conn = put(conn, Routes.developer_path(conn, :update, developer), developer: @update_attrs)
      assert redirected_to(conn) == Routes.developer_path(conn, :show, developer)

      conn = get(conn, Routes.developer_path(conn, :show, developer))
      assert html_response(conn, 200) =~ "some updated email"
    end

    test "renders errors when data is invalid", %{conn: conn, developer: developer} do
      conn = put(conn, Routes.developer_path(conn, :update, developer), developer: @invalid_attrs)
      assert html_response(conn, 200) =~ "Edit Developer"
    end
  end

  describe "delete developer" do
    setup [:create_developer]

    test "deletes chosen developer", %{conn: conn, developer: developer} do
      conn = delete(conn, Routes.developer_path(conn, :delete, developer))
      assert redirected_to(conn) == Routes.developer_path(conn, :index)

      assert_error_sent 404, fn ->
        get(conn, Routes.developer_path(conn, :show, developer))
      end
    end
  end

  defp create_developer(_) do
    developer = developer_fixture()
    %{developer: developer}
  end
end
