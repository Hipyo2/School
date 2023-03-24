defmodule Cs491Hm1Web.ComputerControllerTest do
  use Cs491Hm1Web.ConnCase

  import Cs491Hm1.OfficeAssetsFixtures

  @create_attrs %{brand: "some brand", operating_systems_version: 42}
  @update_attrs %{brand: "some updated brand", operating_systems_version: 43}
  @invalid_attrs %{brand: nil, operating_systems_version: nil}

  describe "index" do
    test "lists all computer", %{conn: conn} do
      conn = get(conn, Routes.computer_path(conn, :index))
      assert html_response(conn, 200) =~ "Listing Computer"
    end
  end

  describe "new computer" do
    test "renders form", %{conn: conn} do
      conn = get(conn, Routes.computer_path(conn, :new))
      assert html_response(conn, 200) =~ "New Computer"
    end
  end

  describe "create computer" do
    test "redirects to show when data is valid", %{conn: conn} do
      conn = post(conn, Routes.computer_path(conn, :create), computer: @create_attrs)

      assert %{id: id} = redirected_params(conn)
      assert redirected_to(conn) == Routes.computer_path(conn, :show, id)

      conn = get(conn, Routes.computer_path(conn, :show, id))
      assert html_response(conn, 200) =~ "Show Computer"
    end

    test "renders errors when data is invalid", %{conn: conn} do
      conn = post(conn, Routes.computer_path(conn, :create), computer: @invalid_attrs)
      assert html_response(conn, 200) =~ "New Computer"
    end
  end

  describe "edit computer" do
    setup [:create_computer]

    test "renders form for editing chosen computer", %{conn: conn, computer: computer} do
      conn = get(conn, Routes.computer_path(conn, :edit, computer))
      assert html_response(conn, 200) =~ "Edit Computer"
    end
  end

  describe "update computer" do
    setup [:create_computer]

    test "redirects when data is valid", %{conn: conn, computer: computer} do
      conn = put(conn, Routes.computer_path(conn, :update, computer), computer: @update_attrs)
      assert redirected_to(conn) == Routes.computer_path(conn, :show, computer)

      conn = get(conn, Routes.computer_path(conn, :show, computer))
      assert html_response(conn, 200) =~ "some updated brand"
    end

    test "renders errors when data is invalid", %{conn: conn, computer: computer} do
      conn = put(conn, Routes.computer_path(conn, :update, computer), computer: @invalid_attrs)
      assert html_response(conn, 200) =~ "Edit Computer"
    end
  end

  describe "delete computer" do
    setup [:create_computer]

    test "deletes chosen computer", %{conn: conn, computer: computer} do
      conn = delete(conn, Routes.computer_path(conn, :delete, computer))
      assert redirected_to(conn) == Routes.computer_path(conn, :index)

      assert_error_sent 404, fn ->
        get(conn, Routes.computer_path(conn, :show, computer))
      end
    end
  end

  defp create_computer(_) do
    computer = computer_fixture()
    %{computer: computer}
  end
end
